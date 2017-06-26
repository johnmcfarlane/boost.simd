//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOG1P_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOG1P_HPP_INCLUDED
#include <boost/simd/function/std.hpp>
#include <boost/simd/function/plain.hpp>

#include <boost/simd/function/scalar/inc.hpp>
#include <boost/simd/function/musl.hpp>
#include <boost/simd/function/scalar/oneminus.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/scalar/inc.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/function/horn.hpp>
#include <boost/simd/function/musl.hpp>
#include <boost/simd/function/plain.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/detail/constant/log_2hi.hpp>
#include <boost/simd/detail/constant/log_2lo.hpp>

#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE
  T log1p_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const&
         , T a0) BOOST_NOEXCEPT
  {
    return std::log1p(a0);
  }

  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T log1p_(BOOST_SIMD_SUPPORTS(cpu_)
        , T a0) BOOST_NOEXCEPT
  {
     return musl_(log1p)(a0);
  }

  //================================================================================================
  // musl decorator
  BOOST_FORCEINLINE
  float log1p_(BOOST_SIMD_SUPPORTS(cpu_)
        , musl_tag const &
        , float x) BOOST_NOEXCEPT
  {
    using ui_t = uint32_t;
    using i_t = int32_t;
    ui_t ix = bitwise_cast<ui_t>(x);
    i_t k = 1;
    float c = Zero<float>(), f = x;
    if (ix < 0x3ed413d0 || ix>>31)               /* 1+x < sqrt(2)+  */
    {
      if (ix >= 0xbf800000)                       /* x <= -1.0 */
      {
        if (x == Mone<float>())  return Minf<float>();  /* log1p(-1)=-inf */
        return Nan<float>();                         /* log1p(x<-1)=NaN */
      }
      if (ix<<1 < 0x33800000<<1)                  /* |x| < 2**-24 */
      {
        if ((ix&0x7f800000) == 0) return x;
      }
      if (ix <= 0xbe95f619)                       /* sqrt(2)/2- <= 1+x < sqrt(2)+ */
      {
        k = 0;
      }
    }
    else if (ix >= 0x7f800000)  return x;
    if (k)
    {
      /* reduce u into [sqrt(2)/2, sqrt(2)] */
      float uf =  inc(x);
      ui_t iu = bitwise_cast<ui_t>(uf);
      iu += 0x3f800000 - 0x3f3504f3;
      k = bitwise_cast<i_t>(iu>>23) - 0x7f;
      /* correction term ~ log(1+x)-log(u), avoid underflow in c/u */
      if (k < 25)
      {
        c = k >= 2 ? oneminus(uf-x) : x-dec(uf);
        c /= uf;
      }

      /* reduce u into [sqrt(2)/2, sqrt(2)] */
      iu = (iu&0x007fffff) + 0x3f3504f3;
      f =  dec(bitwise_cast<float>(iu));
    }
    float s = f/(2.0f + f);
    float z = sqr(s);
    float w = sqr(z);
    float t1= w*horn<float, 0x3eccce13, 0x3e789e26>(w);
    float t2= z*horn<float, 0x3f2aaaaa, 0x3e91e9ee>(w);
    float R = t2 + t1;
    float hfsq = 0.5f*sqr(f);
    float dk = k;
    return  fma(dk, Log_2hi<float>(), ((fma(s, (hfsq+R), dk*Log_2lo<float>()+c) - hfsq) + f));
  }

  BOOST_FORCEINLINE
  double log1p_(BOOST_SIMD_SUPPORTS(cpu_)
             , musl_tag const &
             , double x) BOOST_NOEXCEPT
  {
    using ui_t = uint64_t;
    using i_t = int64_t;
    ui_t hx = bitwise_cast<ui_t>(x) >> 32;
    i_t k = 1;

    double c = Zero<double>(), f = x;
    if (hx < 0x3fda827a || hx>>31)               /* 1+x < sqrt(2)+ */
    {
      if (hx >= 0xbff00000)                      /* x <= -1.0 */
      {
        if (x == Mone<double>()) return Minf<double>();  /* log1p(-1)=-inf */
        return Nan<double>();                        /* log1p(x<-1)=NaN */
      }
      if (hx<<1 < 0x3ca00000<<1)                 /* |x| < 2**-53 */
      {
        if ((hx&0x7ff00000) == 0) return x;
      }
      if (hx <= 0xbfd2bec4)                      /* sqrt(2)/2- <= 1+x < sqrt(2)+ */
      {
        k = 0;
      }
    } else if (hx >= 0x7ff00000) return x;
    if (k)
    {
      /* reduce x into [sqrt(2)/2, sqrt(2)] */
      double uf =  inc(x);
      ui_t hu = bitwise_cast<ui_t>(uf)>>32;
      hu += 0x3ff00000 - 0x3fe6a09e;
      k = (int)(hu>>20) - 0x3ff;
      /* correction term ~ log(1+x)-log(u), avoid underflow in c/u */
      if (k < 54)
      {
        c = k >= 2 ? oneminus(uf-x) : x-dec(uf);
        c /= uf;
      }
      hu =  (hu&0x000fffff) + 0x3fe6a09e;
      f = bitwise_cast<double>( bitwise_cast<ui_t>(hu<<32) | (bitwise_and(0xffffffffull, bitwise_cast<ui_t>(uf))));
      f = dec(f);
    }

    double hfsq = 0.5*sqr(f);
    double s = f/(2.0f + f);
    double z = sqr(s);
    double w = sqr(z);
    double t1= w*horn<double, 0x3fd999999997fa04ll, 0x3fcc71c51d8e78afll, 0x3fc39a09d078c69fll > (w);
    double t2= z*horn<double, 0x3fe5555555555593ll, 0x3fd2492494229359ll
      , 0x3fc7466496cb03dell, 0x3fc2f112df3e5244ll> (w);
    double R = t2 + t1;
    double dk = k;
    return  fma(dk, Log_2hi<double>(), ((fma(s, (hfsq+R), dk*Log_2lo<double>()+c) - hfsq) + f));
  }

  template<typename T>
  BOOST_FORCEINLINE
  T log1p_(BOOST_SIMD_SUPPORTS(cpu_)
        , plain_tag const&
        , T a0) BOOST_NOEXCEPT
  {
    return musl_(log1p)(a0); //the scalar "plain" version of the algorithm is never speedier than the "musl" version.
    // the call is here to allow a scalar fallback to simd calls when the plain version is speedier in simd
  }

} } }


#endif
