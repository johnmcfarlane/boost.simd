//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOG10_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOG10_HPP_INCLUDED


#include <boost/simd/detail/pack.hpp>
#include <boost/config.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/sqrt_2o_2.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/function/horn.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/musl.hpp>
#include <boost/simd/function/plain.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/tofloat.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_minus.hpp>
#include <boost/simd/function/if_dec.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/is_lez.hpp>
#include <boost/simd/function/is_ngez.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  typename  std::enable_if<std::is_floating_point<T>::value,  pack<T,N>>::type
  log10_(BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return musl_(log10)(a0);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  typename  std::enable_if<std::is_integral<T>::value,  pack<T,N>>::type
  log10_(BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return map_to(simd::log10, a0);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> log10_ ( BOOST_SIMD_SUPPORTS(simd_)
                                   , pack<T,N,simd_emulation_> const& a
                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::log10, a);
  }

  //================================================================================================
  // std_ decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> log10_( BOOST_SIMD_SUPPORTS(simd_)
                  , std_tag const&
                  , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return map_to(std_(simd::log10), a);
  }


  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<float,N> log10_( BOOST_SIMD_SUPPORTS(simd_)
                    , musl_tag const&
                    , pack<float,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t   = pack<float,N>;
    using uip_t = pack<uint32_t,N>;
    using ip_t  = pack<int32_t,N>;
    /* origin: FreeBSD /usr/src/lib/msun/src/e_log10f.c */
    /*
     * ====================================================
     * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
     *
     * Developed at SunPro, a Sun Microsystems, Inc. business.
     * Permission to use, copy, modify, and distribute this
     * software is freely granted, provided that this notice
     * is preserved.
     * ====================================================
     */
    const p_t
      ivln10hi ( 4.3432617188e-01), /* 0x3ede6000 */
      ivln10lo (-3.1689971365e-05), /* 0xb804ead9 */
      log10_2hi( 3.0102920532e-01), /* 0x3e9a2080 */
      log10_2lo( 7.9034151668e-07); /* 0x355427db */
    p_t x = a0;
    ip_t k(0);
    auto isnez = is_nez(a0);
#ifndef BOOST_SIMD_NO_DENORMALS
    auto test = is_less(a0, Smallestposval<p_t>())&&isnez;
    if (any(test))
    {
      k = if_minus(test, k, ip_t(25));
      x = if_else(test, x*p_t(33554432ul), x); //2^25
    }
#endif
    uip_t ix = bitwise_cast<uip_t>(x);
    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    ix += 0x3f800000 - 0x3f3504f3;
    k += bitwise_cast<ip_t>(ix>>23) - 0x7f;
    ix = (ix&0x007fffff) + 0x3f3504f3;
    x =  bitwise_cast<p_t>(ix);
    p_t f = dec(x);
    p_t s = f/(2.0f + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t, 0x3eccce13, 0x3e789e26>(w);
    p_t t2= z*horn<p_t, 0x3f2aaaaa, 0x3e91e9ee>(w);
    p_t R = t2 + t1;
    p_t dk = tofloat(k);
    p_t hfsq = Half<p_t>()*sqr(f);

    p_t  hibits = f - hfsq;
    hibits =  bitwise_and(hibits, uip_t(0xfffff000ul));
    p_t  lobits = fma(s, hfsq+R, f - hibits - hfsq);
//      p_t r = ((((dk*log10_2lo + (lobits+hibits)*ivln10lo) + lobits*ivln10hi) + hibits*ivln10hi) + dk*log10_2hi);
    p_t r = fma(dk, log10_2hi,
                fma(hibits, ivln10hi,
                    fma(lobits, ivln10hi,
                        fma(lobits+hibits, ivln10lo, dk*log10_2lo)
                       )
                   )
               );

#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(a0), zz);
  }


  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<double,N> log10_( BOOST_SIMD_SUPPORTS(simd_)
                     , musl_tag const&
                     , pack<double,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<double,N>;
    using uip_t = pack<uint64_t,N>;
    using ip_t  = pack<int64_t,N>;
    /* origin: FreeBSD /usr/src/lib/msun/src/e_log10f.c */
    /*
     * ====================================================
     * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
     *
     * Developed at SunPro, a Sun Microsystems, Inc. business.
     * Permission to use, copy, modify, and distribute this
     * software is freely granted, provided that this notice
     * is preserved.
     * ====================================================
     */
    const p_t
      ivln10hi (4.34294481878168880939e-01), /* 0x3fdbcb7b, 0x15200000 */
      ivln10lo (2.50829467116452752298e-11), /* 0x3dbb9438, 0xca9aadd5 */
      log10_2hi(3.01029995663611771306e-01), /* 0x3FD34413, 0x509F6000 */
      log10_2lo(3.69423907715893078616e-13); /* 0x3D59FEF3, 0x11F12B36 */
    p_t x = a0;
    uip_t hx = bitwise_cast<uip_t>(x) >> 32;
    ip_t k(0);
    auto isnez = is_nez(a0);

#ifndef BOOST_SIMD_NO_DENORMALS
    auto test = is_less(a0, Smallestposval<p_t>())&&isnez;
    if (any(test))
    {
      k = if_minus(test, k, ip_t(54));
      x = if_else(test, x*p_t(18014398509481984ull), x); //2^54
    }
#endif
    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    hx += 0x3ff00000 - 0x3fe6a09e;
    k += bitwise_cast<ip_t>(hx>>20) - 0x3ff;
    hx = (hx&0x000fffff) + 0x3fe6a09e;
    x = bitwise_cast<p_t>(hx<<32 | (bitwise_and(0xffffffffull, bitwise_cast<uip_t>(x))));

    p_t f = dec(x);
    p_t dk = tofloat(k);
    p_t s = f/(2.0f + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t, 0x3fd999999997fa04ll, 0x3fcc71c51d8e78afll, 0x3fc39a09d078c69fll > (w);
    p_t t2= z*horn<p_t, 0x3fe5555555555593ll, 0x3fd2492494229359ll
      , 0x3fc7466496cb03dell, 0x3fc2f112df3e5244ll> (w);
    p_t R = t2 + t1;
    p_t hfsq = Half<p_t>()*sqr(f);
    //      p_t r = -(hfsq-(s*(hfsq+R))-f)*Invlog_10<p_t>()+dk*Log_2olog_10<p_t>(); // fast ?

    /* hi+lo = f - hfsq + s*(hfsq+R) ~ log(1+f) */
    p_t  hi = f - hfsq;
    hi =  bitwise_and(hi, (Allbits<uip_t>() << 32));
    p_t lo = f - hi - hfsq + s*(hfsq+R);

    p_t val_hi = hi*ivln10hi;
    p_t  y = dk*log10_2hi;
    p_t  val_lo = dk*log10_2lo + (lo+hi)*ivln10lo + lo*ivln10hi;


//       /*
//        * Extra precision in for adding y is not strictly needed
//        * since there is no very large cancellation near x = sqrt(2) or
//        * x = 1/sqrt(2), but we do it anyway since it costs little on CPUs
//        * with some parallelism and it reduces the error for many args.
//        */
    p_t w1 = y + val_hi;
    val_lo += (y - w1) + val_hi;
    val_hi = w1;

    p_t r =  val_lo + val_hi;
#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(a0), zz);
  }


  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<float,N>
  log10_( BOOST_SIMD_SUPPORTS(simd_)
        , plain_tag const&
        , pack<float,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<float,N>;
    using uip_t = pack<uint32_t,N>;
    /* origin: FreeBSD /usr/src/lib/msun/src/e_log10f.c */
    /*
     * ====================================================
     * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
     *
     * Developed at SunPro, a Sun Microsystems, Inc. business.
     * Permission to use, copy, modify, and distribute this
     * software is freely granted, provided that this notice
     * is preserved.
     * ====================================================
     */
    const p_t
      ivln10hi ( 4.3432617188e-01), /* 0x3ede6000 */
      ivln10lo (-3.1689971365e-05), /* 0xb804ead9 */
      log10_2hi( 3.0102920532e-01), /* 0x3e9a2080 */
      log10_2lo( 7.9034151668e-07); /* 0x355427db */
    p_t x = a0;
    p_t dk = Zero<p_t>();
    auto isnez = is_nez(a0);
#ifndef BOOST_SIMD_NO_DENORMALS
    auto test = is_less(a0, Smallestposval<p_t>())&&isnez;
    if (any(test))
    {
      dk = if_minus(test, dk, p_t(25));
      x = if_else(test, x*p_t(33554432ul), x);
    }
#endif
    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    p_t kk;
    std::tie(x, kk) = frexp(a0);
    auto  x_lt_sqrthf = (is_greater(Sqrt_2o_2<p_t>(), x));
    dk += if_dec(x_lt_sqrthf, kk);
    p_t f = dec(x+if_else_zero(x_lt_sqrthf, x));
    p_t s = f/(2.0f + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t, 0x3eccce13, 0x3e789e26>(w);
    p_t t2= z*horn<p_t, 0x3f2aaaaa, 0x3e91e9ee>(w);
    p_t R = t2 + t1;
    p_t hfsq = Half<p_t>()*sqr(f);

    p_t  hi = f - hfsq;
    hi =  bitwise_and(hi, uip_t(0xfffff000ul));
    p_t  lo = fma(s, hfsq+R, f - hi - hfsq);
    p_t r = fma(dk, log10_2hi,
                fma(hi, ivln10hi,
                    fma(lo, ivln10hi,
                        fma(lo+hi, ivln10lo, dk*log10_2lo)
                       )
                   )
               );

#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(a0), zz);
  }

  template<std::size_t N>
  BOOST_FORCEINLINE
  pack<double,N>
  log10_( BOOST_SIMD_SUPPORTS(simd_)
        , plain_tag const&
        , pack<double,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<double,N>;
    using uip_t = pack<uint64_t,N>;
    /* origin: FreeBSD /usr/src/lib/msun/src/e_log10f.c */
    /*
     * ====================================================
     * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
     *
     * Developed at SunPro, a Sun Microsystems, Inc. business.
     * Permission to use, copy, modify, and distribute this
     * software is freely granted, provided that this notice
     * is preserved.
     * ====================================================
     */
    const p_t
      ivln10hi (4.34294481878168880939e-01), /* 0x3fdbcb7b, 0x15200000 */
      ivln10lo (2.50829467116452752298e-11), /* 0x3dbb9438, 0xca9aadd5 */
      log10_2hi(3.01029995663611771306e-01), /* 0x3FD34413, 0x509F6000 */
      log10_2lo(3.69423907715893078616e-13); /* 0x3D59FEF3, 0x11F12B36 */
    p_t x = a0;
    p_t dk = Zero<p_t>();
    auto isnez = is_nez(a0);

#ifndef BOOST_SIMD_NO_DENORMALS
    auto test = is_less(a0, Smallestposval<p_t>())&&isnez;
    if (any(test))
    {
      dk = if_minus(test, dk, p_t(54));
      x = if_else(test, x*p_t(18014398509481984ull), x);
    }
#endif
    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    p_t kk;
    std::tie(x, kk) = frexp(a0);
    auto  x_lt_sqrthf = (is_greater(Sqrt_2o_2<p_t>(), x));
    dk += if_dec(x_lt_sqrthf, kk);
    p_t f = dec(x+if_else_zero(x_lt_sqrthf, x));
    p_t s = f/(2.0f + f);
    p_t z = sqr(s);
    p_t w = sqr(z);
    p_t t1= w*horn<p_t, 0x3fd999999997fa04ll, 0x3fcc71c51d8e78afll, 0x3fc39a09d078c69fll > (w);
    p_t t2= z*horn<p_t, 0x3fe5555555555593ll, 0x3fd2492494229359ll
      , 0x3fc7466496cb03dell, 0x3fc2f112df3e5244ll> (w);
    p_t R = t2 + t1;
    p_t hfsq = Half<p_t>()*sqr(f);
    p_t  hi = f - hfsq;
    hi =  bitwise_and(hi, (Allbits<uip_t>() << 32));
    p_t lo = f - hi - hfsq + s*(hfsq+R);

    p_t val_hi = hi*ivln10hi;
    p_t  y = dk*log10_2hi;
    p_t  val_lo = dk*log10_2lo + (lo+hi)*ivln10lo + lo*ivln10hi;


//       /*
//        * Extra precision in for adding y is not strictly needed
//        * since there is no very large cancellation near x = sqrt(2) or
//        * x = 1/sqrt(2), but we do it anyway since it costs little on CPUs
//        * with some parallelism and it reduces the error for many args.
//        */
    p_t w1 = y + val_hi;
    val_lo += (y - w1) + val_hi;
    val_hi = w1;

    p_t r =  val_lo + val_hi;
#ifndef BOOST_SIMD_NO_INFINITIES
    p_t zz = if_else(isnez, if_else(a0 == Inf<p_t>(), Inf<p_t>(), r), Minf<p_t>());
#else
    p_t zz = if_else(isnez, r, Minf<p_t>());
#endif
    return if_nan_else(is_ngez(a0), zz);
  }

} } }

#endif


