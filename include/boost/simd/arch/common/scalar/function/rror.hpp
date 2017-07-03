//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_RROR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_RROR_HPP_INCLUDED

#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/function/rol.hpp>
#include <boost/simd/function/ror.hpp>
#include <type_traits>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_integral<U>::value && std::is_signed<U>::value, T>::type
  rror_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a0
          , U a1) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(assert_good_rotation<T>(a1), "rror : rotation is out of range");
    return (a1 > 0) ? ror(a0, a1) :rol(a0, -a1);
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_unsigned<U>::value, T>::type
  rror_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a0
          , U a1) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(assert_good_shift<T>(a1), "rror : rotation is out of range");
    return  ror(a0, a1);
  }
} } }


#endif
