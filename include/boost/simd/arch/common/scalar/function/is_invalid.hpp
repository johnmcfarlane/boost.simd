//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_INVALID_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_INVALID_HPP_INCLUDED

#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/logical.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
 BOOST_FORCEINLINE bool
  is_invalid_ ( BOOST_SIMD_SUPPORTS(cpu_)
          , bool
          ) BOOST_NOEXCEPT
  {
    return false;
  }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_invalid_( T a0
           , std::true_type const &
           ) BOOST_NOEXCEPT
  {
    return simd::is_nan(a0-a0);
  }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_invalid_( T
           , std::false_type const &
           ) BOOST_NOEXCEPT
  {
    return False<T>();
  }

  template <typename T
            , typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE as_logical_t<T>
  is_invalid_( BOOST_SIMD_SUPPORTS(cpu_)
         , T a0
         ) BOOST_NOEXCEPT
  {
    return s_is_invalid_(a0, std::is_floating_point<T>());
  }

} } }


#endif
