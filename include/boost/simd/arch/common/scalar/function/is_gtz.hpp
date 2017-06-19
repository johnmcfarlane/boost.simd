//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_GTZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_GTZ_HPP_INCLUDED

#include <boost/simd/constant/zero.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE bool
   is_gtz_ ( BOOST_SIMD_SUPPORTS(cpu_)
           , bool a0
           ) BOOST_NOEXCEPT
  {
    return a0;
  }

  template <typename T>
  BOOST_FORCEINLINE logical<T>
  s_is_gtz_( T const & a0
           , std::true_type const &
           ) BOOST_NOEXCEPT
  {
    return a0 != Zero<T>();
  }

  template <typename T>
  BOOST_FORCEINLINE logical<T>
  s_is_gtz_( T a0
           , std::false_type const &
           ) BOOST_NOEXCEPT
  {
    return  (a0 > Zero<T>());
  }

  template <typename T,
            typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE logical<T>
  is_gtz_( BOOST_SIMD_SUPPORTS(cpu_)
         , T a0
         ) BOOST_NOEXCEPT
  {
    return s_is_gtz_(a0, std::is_unsigned<T>());
  }


} } }


#endif
