//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_COSH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_COSH_HPP_INCLUDED
#include <boost/simd/function/std.hpp>

#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/detail/constant/maxlog.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/average.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T cosh_(BOOST_SIMD_SUPPORTS(cpu_)
         , T a0) BOOST_NOEXCEPT
  {
      //////////////////////////////////////////////////////////////////////////////
      // if x = abs(a0) according x < Threshold e =  exp(x) or exp(x/2) is
      // respectively computed
      // *  in the first case cosh (e+rec(e))/2
      // *  in the second     cosh is (e/2)*e (avoiding undue overflow)
      // Threshold is Maxlog - Log_2
      //////////////////////////////////////////////////////////////////////////////
      T x = bs::abs(a0);
      auto test1 = (x > Maxlog<T>()-Log_2<T>());
      T fac =test1 ? Half<T>() : One<T>();
      T tmp = exp(x*fac);
      T tmp1 = Half<T>()*tmp;
      return test1 ?tmp1*tmp : bs::average(tmp, rec(tmp));
  }

  //================================================================================================
  // std_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T cosh_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const&
         , T a) BOOST_NOEXCEPT
  {
    return std::cosh(a);
  }

} } }


#endif
