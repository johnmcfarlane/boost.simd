//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_EQUAL_WITH_EQUAL_NANS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_EQUAL_WITH_EQUAL_NANS_HPP_INCLUDED

#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
 BOOST_FORCEINLINE bool
 is_equal_with_equal_nans_ ( BOOST_SIMD_SUPPORTS(cpu_)
                           , bool a
                           , bool b
                           ) BOOST_NOEXCEPT
 {
   return a == b;
 }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  is_equal_with_equal_nans_( BOOST_SIMD_SUPPORTS(cpu_)
                           , as_logical_t<T> a
                           , as_logical_t<T> b
                           ) BOOST_NOEXCEPT
  {
    return a == b;
  }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_equal_with_equal_nans_( T a0
                             , T a1
                             ,  std::true_type const &
                             ) BOOST_NOEXCEPT
  {
    return (a0 == a1) || (is_nan(a0) && is_nan(a1));
  }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_equal_with_equal_nans_( T a
                             , T b
                             ,  std::false_type const &
                             ) BOOST_NOEXCEPT
  {
    return a == b;
  }


  template <typename T
            ,  typename = typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE auto
  is_equal_with_equal_nans_( BOOST_SIMD_SUPPORTS(cpu_)
                           , T a
                           , T b
                           ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
     s_is_equal_with_equal_nans_(a, b, std::is_floating_point<T>())
  )

} } }


#endif
