//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOG1P_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOG1P_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/config.hpp>


#include <boost/simd/function/any.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/horn.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/is_ngez.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/musl.hpp>
#include <boost/simd/function/plain.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/tofloat.hpp>

#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/sqrt_2o_2.hpp>
#include <boost/simd/constant/two.hpp>

#include <boost/simd/detail/constant/log_2hi.hpp>
#include <boost/simd/detail/constant/log_2lo.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> log1p_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return musl_(log1p)(a0);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_>
  log1p_ ( BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N,simd_emulation_> const& a
         ) BOOST_NOEXCEPT
  {
    return map_to(simd::log1p, a);
  }

  //================================================================================================
  // std_ decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N>
  log1p_( BOOST_SIMD_SUPPORTS(simd_)
        , std_tag const&
        , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return map_to(std_(simd::log1p), a);
  }


  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<float,N> log1p_( BOOST_SIMD_SUPPORTS(simd_)
                    , musl_tag const&
                    , pack<float,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t   = pack<float,N>;
    using uip_t = pack<uint32_t,N>;
    using ip_t  = pack<int32_t,N>;
    const p_t uf =  inc(a0);
    auto isnez = is_nez(uf);

    uip_t iu = bitwise_cast<uip_t>(uf);
    iu += uip_t(0x3f800000 - 0x3f3504f3);
    ip_t k = bitwise_cast<ip_t>(iu>>23) - ip_t(0x7f);
    /* correction term ~ log(1+x)-log(u), avoid underflow in c/u */
    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    iu =(iu&uip_t(0x007fffff)) + uip_t(0x3f3504f3);
    p_t f =  dec(bitwise_cast<p_t>(iu));
    p_t s = f/(Two<p_t>() + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t, 0x3eccce13, 0x3e789e26>(w);
    p_t t2= z*horn<p_t, 0x3f2aaaaa, 0x3e91e9ee>(w);
    p_t R = t2 + t1;
    p_t hfsq = Half<p_t>()*sqr(f);
    p_t dk = tofloat(k);
    p_t  c = if_else( k >= 2, oneminus(uf-a0), a0-dec(uf))/uf;
    p_t r = fma(dk, Log_2hi<p_t>(), ((fma(s, (hfsq+R), dk*Log_2lo<p_t>()+c) - hfsq) + f));
#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(uf), zz);
  }


  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<double,N> log1p_( BOOST_SIMD_SUPPORTS(simd_)
                       , musl_tag const&
                       , pack<double,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<double,N>;
    using uip_t = pack<uint64_t,N>;
    using ip_t  = pack<int64_t,N>;
    const p_t uf =  inc(a0);
    auto isnez = is_nez(uf);

    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    uip_t hu = bitwise_cast<uip_t>(uf)>>32;
    hu += uip_t(0x3ff00000 - 0x3fe6a09e);
    ip_t k = bitwise_cast<ip_t>(hu>>20) - ip_t(0x3ff);
    /* correction term ~ log(1+x)-log(u), avoid underflow in c/u */
    p_t  c =  if_else( k >= 2, oneminus(uf-a0), a0-dec(uf))/uf;
    hu =  (hu&uip_t(0x000fffff)) + uip_t(0x3fe6a09e);
    p_t f = bitwise_cast<p_t>( bitwise_cast<uip_t>(hu<<32) | (bitwise_and(uip_t(0xffffffffull), bitwise_cast<uip_t>(uf))));
    f = dec(f);

    p_t hfsq = Half<p_t>()*sqr(f);
    p_t s = f/(Two<p_t>() + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t, 0x3fd999999997fa04ll, 0x3fcc71c51d8e78afll, 0x3fc39a09d078c69fll > (w);
    p_t t2= z*horn<p_t, 0x3fe5555555555593ll, 0x3fd2492494229359ll
      , 0x3fc7466496cb03dell, 0x3fc2f112df3e5244ll> (w);
    p_t R = t2 + t1;
    p_t dk = tofloat(k);
    p_t r = fma(dk, Log_2hi<p_t>(), ((fma(s, (hfsq+R), dk*Log_2lo<p_t>()+c) - hfsq) + f));

#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(uf), zz);
  }


  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<float,N> log1p_( BOOST_SIMD_SUPPORTS(simd_)
                      , plain_tag const&
                      , pack<float,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<float,N>;
    const p_t uf =  inc(a0);
    auto isnez = is_nez(uf);

    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    p_t k;
    p_t x;
    std::tie(x, k) = frexp(uf);
    auto  x_lt_sqrthf = (Sqrt_2o_2<p_t>() >  x);
    k = if_dec(x_lt_sqrthf, k);
    p_t f = dec(x+if_else_zero(x_lt_sqrthf, x));
    /* correction term ~ log(1+x)-log(u), avoid underflow in c/u */
    p_t  c = if_else( k >= 2, oneminus(uf-a0), a0-dec(uf))/uf;

    p_t s = f/(Two<p_t>() + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t, 0x3eccce13, 0x3e789e26>(w);
    p_t t2= z*horn<p_t, 0x3f2aaaaa, 0x3e91e9ee>(w);
    p_t R = t2 + t1;
    p_t hfsq = Half<p_t>()*sqr(f);
    p_t r = fma(k, Log_2hi<p_t>(), ((fma(s, (hfsq+R), k*Log_2lo<p_t>()+c) - hfsq) + f));
#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(uf), zz);
  }

  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<double,N> log1p_( BOOST_SIMD_SUPPORTS(simd_)
                       , plain_tag const&
                       , pack<double,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<double,N>;
    const p_t uf =  inc(a0);
    auto isnez = is_nez(uf);

    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    p_t k;
    p_t x;
    std::tie(x, k) = frexp(uf);
    auto  x_lt_sqrthf = (Sqrt_2o_2<p_t>() >  x);
    k = if_dec(x_lt_sqrthf, k);
    p_t f = dec(x+if_else_zero(x_lt_sqrthf, x));
    /* correction term ~ log(1+x)-log(u), avoid underflow in c/u */
    p_t  c = if_else( k >= 2, oneminus(uf-a0), a0-dec(uf))/uf;

    p_t hfsq = Half<p_t>()*sqr(f);
    p_t s = f/(Two<p_t>() + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t, 0x3fd999999997fa04ll, 0x3fcc71c51d8e78afll, 0x3fc39a09d078c69fll > (w);
    p_t t2= z*horn<p_t, 0x3fe5555555555593ll, 0x3fd2492494229359ll
      , 0x3fc7466496cb03dell, 0x3fc2f112df3e5244ll> (w);
    p_t R = t2 + t1;
    p_t r = fma(k, Log_2hi<p_t>(), ((fma(s, (hfsq+R), k*Log_2lo<p_t>()+c) - hfsq) + f));

#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(uf), zz);
  }

} } }

#endif


