//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SQR_ABS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SQR_ABS_HPP_INCLUDED

#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  // no peculiar simd implementation. Will be redefined for complex
  template<typename T>
  BOOST_FORCEINLINE
  T sqr_abs_(BOOST_SIMD_SUPPORTS(cpu_)
           , const T& a) BOOST_NOEXCEPT
  {
    return sqr(a);
  }

  template<typename T>
  BOOST_FORCEINLINE
  T sqr_abs_(BOOST_SIMD_SUPPORTS(cpu_)
           , saturated_tag const&
           , const T& a) BOOST_NOEXCEPT
  {
    return saturated_(sqr)(a);
  }

} } }


#endif
