//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_NGEZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_NGEZ_HPP_INCLUDED

#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/false.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
   BOOST_FORCEINLINE bool
   is_ngez_ ( BOOST_SIMD_SUPPORTS(cpu_)
                , bool
                ) BOOST_NOEXCEPT
   {
     return false;
   }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_ngez_( T a0
            , std::true_type
            ) BOOST_NOEXCEPT
  {
    return !(a0 >= Zero<T>());
  }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_ngez_( T
            , std::false_type
            ) BOOST_NOEXCEPT
  {
    return False<T>();
  }

  template <typename T,
            typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE as_logical_t<T>
  is_ngez_( BOOST_SIMD_SUPPORTS(cpu_)
              , T a0
              ) BOOST_NOEXCEPT
  {
    return s_is_ngez_(a0,  std::is_floating_point<T>());
  }


  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  is_ngez_( BOOST_SIMD_SUPPORTS(cpu_)
              , as_logical_t<T> const &
              ) BOOST_NOEXCEPT
  {
    return False<T>();
  }


} } }


#endif
