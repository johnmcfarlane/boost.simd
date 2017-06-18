//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_GEZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_GEZ_HPP_INCLUDED

#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/logical.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE bool
   is_gez_ ( BOOST_SIMD_SUPPORTS(cpu_)
           , bool
           ) BOOST_NOEXCEPT
  {
    return true;
  }

  template <typename T>
  BOOST_FORCEINLINE logical<T>
  s_is_gez_( T
           , std::true_type const &
           ) BOOST_NOEXCEPT
  {
    return True<T>();
  }

  template <typename T>
  BOOST_FORCEINLINE logical<T>
  s_is_gez_( T a0
           , std::false_type const &
           ) BOOST_NOEXCEPT
  {
    return  (a0 >= Zero<T>());
  }

  template <typename T,
            typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE logical<T>
  is_gez_( BOOST_SIMD_SUPPORTS(cpu_)
         , T a0
         ) BOOST_NOEXCEPT
  {
    return s_is_gez_(a0, std::is_unsigned<T>());
  }

} } }


#endif
