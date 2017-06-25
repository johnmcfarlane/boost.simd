//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_UNORD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_UNORD_HPP_INCLUDED
#include <boost/simd/function/std.hpp>

#include <boost/simd/logical.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{

  BOOST_FORCEINLINE bool
  is_unord_ ( BOOST_SIMD_SUPPORTS(cpu_)
            , bool
            , bool
            ) BOOST_NOEXCEPT
  {
    return false;
  }

  template <typename T
            , typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE as_logical_t<T>
  is_unord_( BOOST_SIMD_SUPPORTS(cpu_)
           , logical<T> const &
           , logical<T> const &
           ) BOOST_NOEXCEPT
  {
    return false;
  }

  template <typename T>
  BOOST_FORCEINLINE typename std::enable_if<std::is_arithmetic<T>::value
                                            , as_logical_t<T>>::type
  is_unord_( BOOST_SIMD_SUPPORTS(cpu_)
           , T a0
           , T a1
           ) BOOST_NOEXCEPT
  {
    return (a0!= a0) || (a1!= a1);
  }

} } }

#endif
