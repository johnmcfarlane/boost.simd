//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ERFCX_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ERFCX_HPP_INCLUDED

#include <boost/simd/arch/common/detail/generic/erf_kernel.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/six.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/ratio.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/expx2.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/oneminus.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/function/is_nan.hpp>
#endif
#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/signnz.hpp>
#endif
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  BOOST_FORCEINLINE
  double erfcx_(BOOST_SIMD_SUPPORTS(cpu_)
               , double x) BOOST_NOEXCEPT
  {
#ifndef BOOST_SIMD_NO_INVALIDS
    if(is_nan(x)) return x;
#endif
    double y =  bs::abs(x);
    if (y <= Ratio<double, 15, 32>()) // 0.46875
    {
      double ysq;
      double res = detail::erf_kernel1<double>::erf1(x, y, ysq);
      return oneminus(res)*exp(ysq);
    }
    else if (y <= 4)
    {
      double res = detail::erf_kernel1<double>::erf2(x, y);
      if (is_ltz(x))
      {
        detail::erf_kernel1<double>::finalize3(res, x);
      }
      return res;
    }
    else
    {
      double res = detail::erf_kernel1<double>::erf3(x, y);
      if (is_ltz(x))
      {
        detail::erf_kernel1<double>::finalize3(res, x);
      }
      return res;
    }
  }

  BOOST_FORCEINLINE
  float erfcx_(BOOST_SIMD_SUPPORTS(cpu_)
              , float a0) BOOST_NOEXCEPT
  {
#ifndef BOOST_SIMD_NO_INFINITIES
    if(a0 == Inf<float>()) return Zero<float>();
    if(is_nan(a0)) return a0;
#endif
    if (a0 < Ratio<float, 2, 3>())
    {
      return expx2(a0)*erfc(a0);
    }
    else
    {
      float z =  a0/inc(a0) - Ratio<float, 2, 5>();
      return detail::erf_kernel<float>::erfc2(z);
    }
  }

} } }


#endif
