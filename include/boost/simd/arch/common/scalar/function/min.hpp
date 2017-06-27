//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MIN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MIN_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/std.hpp>
#include <type_traits>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  ///////////////////////////////////////////////////////////////////////
  // regular
  template<typename T>
  BOOST_FORCEINLINE T
  min_(BOOST_SIMD_SUPPORTS(cpu_)
      , T a0
      , T a1) BOOST_NOEXCEPT
  {
    return (a1 <  a0) ? a1 : a0;
  }

  ///////////////////////////////////////////////////////////////////////
  // pedantic

  template<typename T>
  BOOST_FORCEINLINE T
  min_(BOOST_SIMD_SUPPORTS(cpu_)
      , T a0
      , T a1, std::true_type const &) BOOST_NOEXCEPT
  {
    return (a1 <  a0) ? a1 : a0;
  }

  ///////////////////////////////////////////////////////////////////////
  // std

  template<typename T>
  BOOST_FORCEINLINE T
  min_(BOOST_SIMD_SUPPORTS(cpu_)
      , std_tag const &
      , T a0
      , T a1) BOOST_NOEXCEPT
  {
    return std::min(a0, a1);
  }

} } }


#endif

