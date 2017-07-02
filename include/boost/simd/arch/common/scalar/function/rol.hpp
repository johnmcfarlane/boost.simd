//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ROL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ROL_HPP_INCLUDED

#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/shl.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_integral<U>::value, T>::type
  rol_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a0
          , U a1) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(assert_good_shift<T>(a1), "rol : rotation is out of range");

    constexpr std::size_t width = sizeof(T)*CHAR_BIT-1;
    std::size_t n = a1;
    return shl(a0, n) | shr(a0, (-n&width));
  }

} } }


#endif

