//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOG_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/config.hpp>

#include <boost/simd/function/any.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/function/horn.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_minus.hpp>
#include <boost/simd/function/if_dec.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/is_ngez.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/musl.hpp>
#include <boost/simd/function/plain.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/tofloat.hpp>

#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/sqrt_2o_2.hpp>
#include <boost/simd/constant/two.hpp>

#include <boost/simd/detail/constant/log_2hi.hpp>
#include <boost/simd/detail/constant/log_2lo.hpp>


////////////////////////////////////////////////////////////////////////////////////
// Two implementations are given "musl_" and "plain_"
// They differ by the reduction step.
// The "plain" implementation of log is mainly for avx,  because avx does not have
// good support for integral vector types. "plain" uses frexp instead of ifrexp to run
// all the process with floting vector types
// The correct dispatch of log is done in each architecture related file or
// default to musl_
////////////////////////////////////////////////////////////////////////////////////

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> log_(BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return musl_(log)(a0);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> log_ ( BOOST_SIMD_SUPPORTS(simd_)
                                 , pack<T,N,simd_emulation_> const& a
                                 ) BOOST_NOEXCEPT
  {
    return map_to(simd::log, a);
  }

  //================================================================================================
  // std_ decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> log_( BOOST_SIMD_SUPPORTS(simd_)
                  , std_tag const&
                  , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return map_to(std_(simd::log), a);
  }


  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<float,N> log_( BOOST_SIMD_SUPPORTS(simd_)
                    , musl_tag const&
                    , pack<float,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t   = pack<float,N>;
    using uip_t = pack<uint32_t,N>;
    using ip_t  = pack<int32_t,N>;
    p_t x =  a0;
    ip_t k(0);
    auto isnez = is_nez(a0);
#ifndef BOOST_SIMD_NO_DENORMALS
    auto test = is_less(a0, Smallestposval<p_t>())&&isnez;
    if (any(test))
    {
      k = if_minus(test, k, ip_t(23));
      x = if_else(test, x*p_t(8388608ul), x);
    }
#endif
    uip_t ix = bitwise_cast<uip_t>(x);
    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    ix += uip_t(0x3f800000 - 0x3f3504f3);
    k += bitwise_cast<ip_t>(ix>>23) - ip_t(0x7f);
    ix = (ix&uip_t(0x007fffff)) + uip_t(0x3f3504f3);
    x =  bitwise_cast<p_t>(ix);
    p_t f = dec(x);
    p_t s = f/(Two<p_t>() + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t, 0x3eccce13, 0x3e789e26>(w);
    p_t t2= z*horn<p_t, 0x3f2aaaaa, 0x3e91e9ee>(w);
    p_t R = t2 + t1;

    p_t hfsq = Half<p_t>()*sqr(f);
    p_t dk = tofloat(k);
    p_t r = fma(dk, Log_2hi<p_t>(), ((fma(s, (hfsq+R), dk*Log_2lo<p_t>()) - hfsq) + f));
#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(a0), zz);
  }


  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<double,N> log_( BOOST_SIMD_SUPPORTS(simd_)
                     , musl_tag const&
                     , pack<double,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<double,N>;
    using uip_t = pack<uint64_t,N>;
    using ip_t  = pack<int64_t,N>;
    p_t x = a0;
    uip_t hx = bitwise_cast<uip_t>(x) >> 32;
    ip_t k(0);
    auto isnez = is_nez(a0);

#ifndef BOOST_SIMD_NO_DENORMALS
    auto test = is_less(a0, Smallestposval<p_t>())&&isnez;
    if (any(test))
    {
      k = if_minus(test, k, ip_t(54));
      x = if_else(test, x*p_t(18014398509481984ull), x);
    }
#endif
    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    hx += uip_t(0x3ff00000 - 0x3fe6a09e);
    k += bitwise_cast<ip_t>(hx>>20) - ip_t(0x3ff);
    p_t dk = tofloat(k);
    hx = (hx&uip_t(0x000fffff)) + uip_t(0x3fe6a09e);
    x = bitwise_cast<p_t>(hx<<32 | (bitwise_and(uip_t(0xffffffffull), bitwise_cast<uip_t>(x))));

    p_t f = dec(x);
    p_t hfsq = Half<p_t>()*sqr(f);
    p_t s = f/(Two<p_t>() + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t,
      0x3fd999999997fa04ll,
      0x3fcc71c51d8e78afll,
      0x3fc39a09d078c69fll
      > (w);
    p_t t2= z*horn<p_t,
      0x3fe5555555555593ll,
      0x3fd2492494229359ll,
      0x3fc7466496cb03dell,
      0x3fc2f112df3e5244ll
      > (w);
    p_t R = t2+t1;
    p_t r = fma(dk, Log_2hi<p_t>(), ((fma(s, (hfsq+R), dk*Log_2lo<p_t>()) - hfsq) + f));
#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(a0), zz);
  }


  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<float,N> log_( BOOST_SIMD_SUPPORTS(simd_)
                    , plain_tag const&
                    , pack<float,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<float,N>;
    p_t x =  a0;
    p_t dk = Zero<p_t>();
    auto isnez = is_nez(a0);
#ifndef BOOST_SIMD_NO_DENORMALS
    auto test = is_less(a0, Smallestposval<p_t>())&&isnez;
    if (any(test))
    {
      dk = if_minus(test, dk, p_t(23));
      x = if_else(test, x*p_t(8388608ul), x);
    }
#endif
    p_t kk;
    std::tie(x, kk) = frexp(x);
    auto  x_lt_sqrthf = (Sqrt_2o_2<p_t>() > x);
    dk += if_dec(x_lt_sqrthf, kk);
    p_t f = dec(x+if_else_zero(x_lt_sqrthf, x));
    p_t s = f/(Two<p_t>() + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t, 0x3eccce13, 0x3e789e26>(w);
    p_t t2= z*horn<p_t, 0x3f2aaaaa, 0x3e91e9ee>(w);
    p_t R = t2 + t1;
    p_t hfsq = Half<p_t>()*sqr(f);
    p_t r = fma(dk, Log_2hi<p_t>(), ((fma(s, (hfsq+R), dk*Log_2lo<p_t>()) - hfsq) + f));
#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(a0), zz);
  }


  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<double,N> log_( BOOST_SIMD_SUPPORTS(simd_)
                     , plain_tag const&
                     , pack<double,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<double,N>;
    p_t x =  a0;
    p_t dk = Zero<p_t>();
    auto isnez = is_nez(a0);
#ifndef BOOST_SIMD_NO_DENORMALS
    auto test = is_less(a0, Smallestposval<p_t>())&&isnez;
    if (any(test))
    {
      dk = if_minus(test, dk, p_t(23));
      x = if_else(test, x*p_t(8388608ul), x);
    }
#endif
    p_t kk;
    std::tie(x, kk) = frexp(x);
    auto  x_lt_sqrthf = (Sqrt_2o_2<p_t>() > x);
    dk += if_dec(x_lt_sqrthf, kk);
    p_t f = dec(x+if_else_zero(x_lt_sqrthf, x));

    // compute approximation
    p_t s = f/(Two<p_t>()+f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t,
      0x3fd999999997fa04ll,
      0x3fcc71c51d8e78afll,
      0x3fc39a09d078c69fll
      > (w);
    p_t t2= z*horn<p_t,
      0x3fe5555555555593ll,
      0x3fd2492494229359ll,
      0x3fc7466496cb03dell,
      0x3fc2f112df3e5244ll
      > (w);
    p_t R = t2+t1;
    p_t hfsq = Half<p_t>()* sqr(f);
    p_t r = fma(dk, Log_2hi<p_t>(), ((fma(s, (hfsq+R), dk*Log_2lo<p_t>()) - hfsq) + f));
#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(a0), zz);
  }

} } }

#endif
/*
 *   1. Argument Reduction: find k and f such that
 *                      x = 2^k * (1+f),
 *         where  sqrt(2)/2 < 1+f < sqrt(2) .
 *
 *   2. Approximation of log(1+f).
 *      Let s = f/(2+f) ; based on log(1+f) = log(1+s) - log(1-s)
 *               = 2s + 2/3 s**3 + 2/5 s**5 + .....,
 *               = 2s + s*R
 *      We use a special Remez algorithm on [0,0.1716] to generate
 *      a polynomial of degree 14 to approximate R The maximum error
 *      of this polynomial approximation is bounded by 2**-58.45. In
 *      other words,
 *                      2      4      6      8      10      12      14
 *          R(z) ~ Lg1*s +Lg2*s +Lg3*s +Lg4*s +Lg5*s  +Lg6*s  +Lg7*s
 *      (the values of Lg1 to Lg7 are listed in the program)
 *      and
 *          |      2          14          |     -58.45
 *          | Lg1*s +...+Lg7*s    -  R(z) | <= 2
 *          |                             |
 *      Note that 2s = f - s*f = f - hfsq + s*hfsq, where hfsq = f*f/2.
 *      In order to guarantee error in log below 1ulp, we compute log
 *      by
 *              log(1+f) = f - s*(f - R)        (if f is not too large)
 *              log(1+f) = f - (hfsq - s*(hfsq+R)).     (better accuracy)
 *
 *      3. Finally,  log(x) = k*ln2 + log(1+f).
 *                          = k*ln2_hi+(f-(hfsq-(s*(hfsq+R)+k*ln2_lo)))
 *         Here ln2 is split into two floating point number:
 *                      ln2_hi + ln2_lo,
 *         where n*ln2_hi is always exact for |n| < 2000.
 */



