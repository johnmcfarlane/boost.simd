//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOG10_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_LOG10_HPP_INCLUDED
#include <boost/simd/function/std.hpp>
#include <boost/simd/function/plain.hpp>

#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/simd/constant/log_2olog_10.hpp>
#include <boost/simd/constant/invlog_10.hpp>
#include <boost/simd/function/nearbyint.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/detail/constant/invlog_10hi.hpp>
#include <boost/simd/detail/constant/invlog_10lo.hpp>
#include <boost/simd/detail/constant/log10_2hi.hpp>
#include <boost/simd/detail/constant/log10_2lo.hpp>

#include <boost/assert.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <type_traits>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/function/horn.hpp>
#include <boost/simd/function/musl.hpp>
#include <boost/simd/function/plain.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/std.hpp>

#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/simd/detail/meta/size_picker.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE
  T log10_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const&
         , T a0) BOOST_NOEXCEPT
  {
    return std::log10(a0);
  }

  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  typename  std::enable_if<std::is_floating_point<T>::value, T>::type
  log10_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a0) BOOST_NOEXCEPT
  {
    return musl_(log10)(a0);
  }

  //================================================================================================
  // musl decorator
  BOOST_FORCEINLINE
  float log10_(BOOST_SIMD_SUPPORTS(cpu_)
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
    float hfsq = Half<float>()*sqr(f);
//      return -(hfsq-(s*(hfsq+R))-f)*Invlog_10<float>()+k*Log_2olog_10<float>(); // fast ?

    float hibits = f - hfsq;
    hibits =  bitwise_and(hibits, ui_t(0xfffff000ul));
    float  lobits = fma(s, hfsq+R, f - hibits - hfsq);
    float dk = k;
//      return ((((dk*Log10_2lo<float> + (lobits+hibits)*Invlog_10lo<float>()) + lobits*Invlog_10hi<float>()) + hibits*Invlog_10hi<float>()) + dk*Log10_2hi<float>());
    return fma(dk, Log10_2hi<float>(),
               fma(hibits, Invlog_10hi<float>(),
                   (fma(lobits, Invlog_10hi<float>(),
                        fma(lobits+hibits, Invlog_10lo<float>(), dk*Log10_2lo<float>())
                       )
                   )
                  )
              );
  }

  BOOST_FORCEINLINE
  double log10_(BOOST_SIMD_SUPPORTS(cpu_)
               , musl_tag const &
               , double x) BOOST_NOEXCEPT
  {
    using ui_t = uint64_t;
    using i_t = int64_t;
    /* origin: FreeBSD /usr/src/lib/msun/src/e_log10.c */
    /*
     * ====================================================
     * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
     *
     * Developed at SunSoft, a Sun Microsystems, Inc. business.
     * Permission to use, copy, modify, and distribute this
     * software is freely granted, provided that this notice
     * is preserved.
     * ====================================================
     */
    ui_t hx = bitwise_cast<ui_t>(x) >> 32;
    i_t k = 0;
    if (hx < 0x00100000 || hx>>31)
    {
      if(is_eqz(x))
        return Minf<double>();  /* log(+-0)=-inf */
      if (hx>>31)
        return Nan<double>(); /* log(-#) = NaN */
      /* subnormal number, scale x up */
      k -= 54;
      x *= 18014398509481984.0;
      hx = bitwise_cast<ui_t>(x) >> 32;
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
    double hfsq = Half<double>()*sqr(f);
    double s = f/(2.0f + f);
    double z = sqr(s);
    double w = sqr(z);
    double t1= w*horn<double, 0x3fd999999997fa04ll, 0x3fcc71c51d8e78afll, 0x3fc39a09d078c69fll > (w);
    double t2= z*horn<double, 0x3fe5555555555593ll, 0x3fd2492494229359ll
      , 0x3fc7466496cb03dell, 0x3fc2f112df3e5244ll> (w);
    double R = t2 + t1;
    double dk = k;
    //          return -(hfsq-(s*(hfsq+R))-f)*Invlog_10<double>()+dk*Log_2olog_10<double>(); //fast ?

    double  hi = f - hfsq;
    hi =  bitwise_and(hi, (Allbits<ui_t>() << 32));

    double lo = f - hi - hfsq + s*(hfsq+R);

    /* val_hi+val_lo ~ log10(1+f) + k*log10(2) */
    double val_hi = hi*Invlog_10hi<double>();
    double y = dk*Log10_2hi<double>();
    double val_lo = fma(dk, Log10_2lo<double>(),  fma(lo+hi, Invlog_10lo<double>(),  lo*Invlog_10hi<double>()));

//       /*
//        * Extra precision in for adding y is not strictly needed
//        * since there is no very large cancellation near x = sqrt(2) or
//        * x = 1/sqrt(2), but we do it anyway since it costs little on CPUs
//        * with some parallelism and it reduces the error for many args.
//        */
    double w1 = y + val_hi;
    val_lo += (y - w1) + val_hi;
    val_hi = w1;

    return val_lo + val_hi;
  }


  BOOST_FORCEINLINE
  std::uint64_t si_log10_(std::uint64_t a0
                         , case_<0> const &) BOOST_NOEXCEPT
  {
    return(a0 >= 10000000000000000000ull) ? 19 :
      (a0 >= 1000000000000000000ull) ?  18 :
      (a0 >= 100000000000000000ull) ?   17 :
      (a0 >= 10000000000000000ull) ?    16 :
      (a0 >= 1000000000000000ull) ?     15 :
      (a0 >= 100000000000000ull) ?      14 :
      (a0 >= 10000000000000ull) ?       13 :
      (a0 >= 1000000000000ull) ?        12 :
      (a0 >= 100000000000ull) ?         11 :
      (a0 >= 10000000000ull) ?          10 :
      (a0 >= 1000000000ull) ?            9 :
      (a0 >= 100000000ull) ?             8 :
      (a0 >= 10000000ull) ?              7 :
      (a0 >= 1000000ull) ?               6 :
      (a0 >= 100000ull) ?                5 :
      (a0 >= 10000ull) ?                 4 :
      (a0 >= 1000ull) ?                  3 :
      (a0 >= 100ull) ?                   2 :
      (a0 >= 10ull) ?                    1 : 0;
  }
  BOOST_FORCEINLINE
  std::uint32_t si_log10_(std::uint32_t a0
                         , case_<1> const &) BOOST_NOEXCEPT
  {
    return (a0 >= 1000000000u) ? 9 :
      (a0 >= 100000000u) ?  8 :
      (a0 >= 10000000u) ?   7 :
      (a0 >= 1000000u) ?    6 :
      (a0 >= 100000u) ?     5 :
      (a0 >= 10000u) ?      4 :
      (a0 >= 1000u) ?       3 :
      (a0 >= 100u) ?        2 :
      (a0 >= 10u) ?         1 : 0;
  }

  BOOST_FORCEINLINE
  std::uint16_t si_log10_(std::uint16_t a0
                         , case_<2> const &) BOOST_NOEXCEPT
  {
    return (a0 >= 10000u) ? 4 :
      (a0 >= 1000u)  ? 3 :
      (a0 >= 100u)   ? 2 :
      (a0 >= 10u)    ? 1 : 0;
  }

  BOOST_FORCEINLINE
  std::uint8_t si_log10_(std::uint8_t a0
                        , case_<3> const &) BOOST_NOEXCEPT
  {
    return (a0 >= 100u) ? 2 :
      (a0 >= 10u)  ? 1 : 0;
  }

  template < typename T >
  BOOST_FORCEINLINE
  T s_log10_( T a
            , std::false_type const &) BOOST_NOEXCEPT
  {
    return si_log10_(a, size_picker<T>());
  }

  template < typename T >
  BOOST_FORCEINLINE
  T s_log10_(T a
            , std::true_type const &) BOOST_NOEXCEPT
  {
    using ui_t = ui_t<T>;
    BOOST_ASSERT_MSG( a > 0, "log10 is not defined for zero or negative integers." );
    return T(si_log10_(ui_t(a), size_picker<T>()));
  }

  template < typename T>
  BOOST_FORCEINLINE
  typename  std::enable_if<std::is_integral<T>::value, T>::type
  log10_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a) BOOST_NOEXCEPT
  {
    return s_log10_(a,std::is_signed<T>());
  }

  template < typename T>
  BOOST_FORCEINLINE
  T
  log10_(BOOST_SIMD_SUPPORTS(cpu_)
          , plain_tag const &
          , T a) BOOST_NOEXCEPT
  {
    return  musl_(log10)(a);  //the scalar "plain" version of the algorithm is never speedier than the "musl" version.
    // the call is here to allow a scalar fallback to simd calls when the plain version is speedier in simd
  }
  }

} } }

#endif

