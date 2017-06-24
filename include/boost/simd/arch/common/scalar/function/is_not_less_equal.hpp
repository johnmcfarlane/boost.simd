//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_NOT_LESS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_NOT_LESS_EQUAL_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/is_unord.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE bool
  is_not_less_equal_ ( BOOST_SIMD_SUPPORTS(cpu_)
                     , bool a
                     , bool b
                     ) BOOST_NOEXCEPT
  {
    return a > b;
  }

  template <typename T
            , typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE as_logical_t<T>
  is_not_less_equal_( BOOST_SIMD_SUPPORTS(cpu_)
                       , logical<T> const &a
                       , logical<T> const &b
                       ) BOOST_NOEXCEPT
  {
    return a.value() > b.value();
  }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_not_less_equal_( T a
                      , T b
                      ,  std::true_type  const &
                      ) BOOST_NOEXCEPT
  {
    return (a > b) || is_unord(a, b);
  }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_not_less_equal_( T a
                      , T b
                      ,  std::false_type  const &
                      ) BOOST_NOEXCEPT
  {
    return a > b;
  }

  template <typename T
            , typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE as_logical_t<T>
  is_not_less_equal_( BOOST_SIMD_SUPPORTS(cpu_)
                    , T a
                    , T b
                    ) BOOST_NOEXCEPT
  {
    return s_is_not_less_equal_(a, b,  std::is_floating_point<T>());
  }

} } }

#endif
