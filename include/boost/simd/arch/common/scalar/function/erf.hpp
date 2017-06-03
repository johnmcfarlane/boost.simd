//==================================================================================================
/**
  Copyright 201 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ERF_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ERF_HPP_INCLUDED

#include <boost/simd/function/std.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/oneminus.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/sign.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/arch/common/detail/generic/erf_kernel.hpp>

#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/function/is_nan.hpp>
#endif
#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/signnz.hpp>
#endif

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  BOOST_FORCEINLINE
  double erf_(BOOST_SIMD_SUPPORTS(cpu_)
             , double x) BOOST_NOEXCEPT
  {
#ifndef BOOST_SIMD_NO_INVALIDS
    if(is_nan(x)) return x;
#endif
    double y = bs::abs(x);
    if (y <= Ratio<double, 15, 32>()) // 0.46875
    {
      return detail::erf_kernel1<double>::erf1(x, y);
    }
    else if (y <= 4)
    {
      double res = detail::erf_kernel1<double>::erf2(x, y);
      res =    detail::erf_kernel1<double>::finalize2(res, y);
      res = (Half<double>() - res) + Half<double>();
      if (is_ltz(x)) res = -res;
      return res;
    }
    else if  (y <= 26.543)
    {
      double res = detail::erf_kernel1<double>::erf3(x, y);
      res =    detail::erf_kernel1<double>::finalize2(res, y);
      res = (Half<double>() - res) + Half<double>();
      if (is_ltz(x)) res = -res;
      return res;
    }
    else return sign(x);
  }


  BOOST_FORCEINLINE
  float erf_(BOOST_SIMD_SUPPORTS(cpu_)
            , float a0) BOOST_NOEXCEPT
  {
#ifndef BOOST_SIMD_NO_INVALIDS
    if(is_nan(a0)) return a0;
#endif

#ifndef BOOST_SIMD_NO_INFINITIES
    if (bs::is_inf(a0)) return signnz(a0);
#endif

    float x =  bs::abs(a0);
    if (x < Ratio<float, 2, 3>())
    {
      return a0*detail::erf_kernel<float>::erf1(sqr(x));
    }
    else
    {
      float z = x/inc(x)-Ratio<float, 2, 5>();
      float r2 = oneminus(exp(-sqr(x))*detail::erf_kernel<float>::erfc2(z));
      if (is_ltz(a0)) r2 = -r2;
      return r2;
    }
  }

  //================================================================================================
  // std_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T cos_(BOOST_SIMD_SUPPORTS(cpu_)
        , std_tag const&
        , T const& a) BOOST_NOEXCEPT
  {
    return std::erf(a);
  }

} } }

#endif
