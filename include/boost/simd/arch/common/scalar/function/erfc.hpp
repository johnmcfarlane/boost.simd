//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ERFC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ERFC_HPP_INCLUDED

#include <boost/simd/function/std.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/arch/common/detail/generic/erf_kernel.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/oneminus.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/function/rec.hpp>
#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/function/is_nan.hpp>
#endif
#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/constant/inf.hpp>
#endif
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  BOOST_FORCEINLINE
  double erfc_(BOOST_SIMD_SUPPORTS(cpu_)
              , double x) BOOST_NOEXCEPT
  {
#ifndef BOOST_SIMD_NO_INVALIDS
    if(is_nan(x)) return x;
#endif
    double y =  bs::abs(x);
    if (y <= Ratio<double, 15, 32>()) // 0.46875
    {
      double res = detail::erf_kernel1<double>::erf1(x, y);
      res =  oneminus(res);
      return res;
    }
    else if (y <= Ratio<double, 4>())
    {
      double res = detail::erf_kernel1<double>::erf2(x, y);
      res =    detail::erf_kernel1<double>::finalize2(res, y);
      if (is_ltz(x)) res = Two<double>()-res;
      return res;
    }
    else if  (y <= 26.543)
    {
      double res = detail::erf_kernel1<double>::erf3(x, y);
      res =    detail::erf_kernel1<double>::finalize2(res, y);
      if (is_ltz(x)) res = Two<double>()-res;
      return res;
    }
    else return (is_ltz(x)) ? Two<double>() : Zero<double>();
  }

  BOOST_FORCEINLINE
  float erfc_(BOOST_SIMD_SUPPORTS(cpu_)
            , float a0) BOOST_NOEXCEPT
  {
    float x =  bs::abs(a0);
    float r1 = Zero<float>();
    float z =  x/inc(x);
    if (x < Ratio<float, 2, 3>())
    {
      r1 = detail::erf_kernel<float>::erfc3(z);
    }
#ifndef BOOST_SIMD_NO_INFINITIES
    else if (BOOST_UNLIKELY(x == Inf<float>()))
    {
      r1 = Zero<float>();
    }
#endif
    else
    {
      z-= 0.4f;
      r1 = exp(-sqr(x))*detail::erf_kernel<float>::erfc2(z);
    }
    return (a0 < 0.0f) ? 2.0f-r1 : r1;
  }

  //================================================================================================
  // std_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T erfc_(BOOST_SIMD_SUPPORTS(cpu_)
        , std_tag const&
        , T const& a) BOOST_NOEXCEPT
  {
    return std::erfc(a);
  }

} } }


#endif
