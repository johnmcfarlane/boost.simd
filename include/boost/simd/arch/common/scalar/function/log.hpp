//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOG_HPP_INCLUDED
#include <boost/simd/function/std.hpp>

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/function/musl.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/assert.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/function/horn.hpp>
#include <boost/simd/function/musl.hpp>
#include <boost/simd/function/plain.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/std.hpp>

#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/sqrt_2o_2.hpp>

#include <boost/simd/detail/constant/log_2hi.hpp>
#include <boost/simd/detail/constant/log_2lo.hpp>

#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE
  T log_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const&
         , T a0) BOOST_NOEXCEPT
  {
    return std::log(a0);
  }

  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T log_(BOOST_SIMD_SUPPORTS(cpu_)
        , T a0) BOOST_NOEXCEPT
  {
     return musl_(log)(a0);
  }

  //================================================================================================
  // musl decorator
  BOOST_FORCEINLINE
  float log_(BOOST_SIMD_SUPPORTS(cpu_)
        , musl_tag const &
        , float x) BOOST_NOEXCEPT
  {
    /* origin: FreeBSD /usr/src/lib/msun/src/e_log2f.c */
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
    using ui_t = uint32_t;
    using i_t = int32_t;
    ui_t ix = bitwise_cast<ui_t>(x);
    i_t k = 0;
    if (ix < 0x00800000 || ix>>31)         /* x < 2**-126  */
    {
      if (ix<<1 == 0) return Minf<float>();  /* log(+-0)=-inf */
      if (ix>>31) return Nan<float>();       /* log(-#) = NaN */
#ifndef BOOST_SIMD_NO_DENORMALS
      /* subnormal number, scale up x */
      k -= 25;
      x *= 33554432.0f;
      ix = bitwise_cast<i_t>(x);
#endif
    }
    else if (ix >= 0x7f800000)
    {
      return x;
    }
    else if (ix == 0x3f800000)
      return 0;

    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    ix += 0x3f800000 - 0x3f3504f3;
    k += bitwise_cast<i_t>(ix>>23) - 0x7f;
    ix = (ix&0x007fffff) + 0x3f3504f3;
    x =  bitwise_cast<float>(ix);
    float f = dec(x);
    float s = f/(2.0f + f);
    float z = sqr(s);
    float w = sqr(z);
    float t1= w*horn<float, 0x3eccce13, 0x3e789e26>(w);
    float t2= z*horn<float, 0x3f2aaaaa, 0x3e91e9ee>(w);
    float R = t2 + t1;
    float hfsq = 0.5f*sqr(f);
    float dk = k;
    return  fma(dk, Log_2hi<float>(), ((fma(s, (hfsq+R), dk*Log_2lo<float>()) - hfsq) + f));
  }

  BOOST_FORCEINLINE
  double log_(BOOST_SIMD_SUPPORTS(cpu_)
        , musl_tag const &
        , double x) BOOST_NOEXCEPT
  {
    using ui_t = uint64_t;
    using i_t = int64_t;
    ui_t hx = bitwise_cast<ui_t>(x) >> 32;
    i_t k = 0;
    if (hx < 0x00100000 || hx>>31)
    {
      if(is_eqz(x)) return Minf<double>();  /* log(+-0)=-inf */
      if (hx>>31)   return Nan<double>();   /* log(-#) = NaN */
#ifndef BOOST_SIMD_NO_DENORMALS
      /* subnormal number, scale x up */
      k -= 54;
      x *= 18014398509481984.0;
      hx = bitwise_cast<ui_t>(x) >> 32;
#endif
    }
    else if (hx >= 0x7ff00000)
    {
      return x;
    }
    else if (x == One<double>())
      return Zero<double>();

    /* reduce x into [sqrt(2)/2, sqrt(2)] */
    hx += 0x3ff00000 - 0x3fe6a09e;
    k += bitwise_cast<i_t>(hx>>20) - 0x3ff;
    hx = (hx&0x000fffff) + 0x3fe6a09e;
    x = bitwise_cast<double>( (uint64_t)hx<<32 | (bitwise_and(0xffffffffull, bitwise_cast<ui_t>(x))));

    double f = dec(x);
    double hfsq = 0.5*sqr(f);
    double s = f/(2.0f + f);
    double z = sqr(s);
    double w = sqr(z);
    double t1= w*horn<double, 0x3fd999999997fa04ll, 0x3fcc71c51d8e78afll, 0x3fc39a09d078c69fll > (w);
    double t2= z*horn<double, 0x3fe5555555555593ll, 0x3fd2492494229359ll
      , 0x3fc7466496cb03dell, 0x3fc2f112df3e5244ll> (w);
    double R = t2 + t1;
    double dk = k;
    return  fma(dk, Log_2hi<double>(), ((fma(s, (hfsq+R), dk*Log_2lo<double>()) - hfsq) + f));
  }

  template<typename T>
  BOOST_FORCEINLINE
  T log_(BOOST_SIMD_SUPPORTS(cpu_)
        , plain_tag const&
        , T a0) BOOST_NOEXCEPT
  {
    return musl_(log)(a0); //the scalar "plain" version of the algorithm is never speedier than the "musl" version.
    // the call is here to allow a scalar fallback to simd calls when the plain version is speedier in simd
  }

} } }

#endif
