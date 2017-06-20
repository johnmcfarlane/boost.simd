//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_LESSGREATER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_LESSGREATER_HPP_INCLUDED

#include <boost/simd/function/std.hpp>
#include <boost/config.hpp>
#include <boost/simd/function/is_ord.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <type_traits>
#include <cmath>

namespace boost { namespace simd { namespace detail
{

  BOOST_FORCEINLINE bool
  is_lessgreater_ ( BOOST_SIMD_SUPPORTS(cpu_)
           , bool a
           , bool b
           ) BOOST_NOEXCEPT
  {
    return a!=b;
  }

  template <typename T
            , typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE as_logical_t<T>
  is_lessgreater_( BOOST_SIMD_SUPPORTS(cpu_)
          , logical<T> const & a
          , logical<T> const & b
          ) BOOST_NOEXCEPT
  {
    return a != b;
  }

  template <typename T >
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_lessgreater_( T a0
                 , T a1
                 ,  std::true_type const &
                 ) BOOST_NOEXCEPT
  {
    return (a0!=a1)&&is_ord(a0,a1);
  }

  template <typename T >
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_lessgreater_( T a0
                 , T a1
                 ,  std::false_type const &
                 ) BOOST_NOEXCEPT
  {
    return (a0!=a1);
  }


  template <typename T
            , typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE as_logical_t<T>
  is_lessgreater_( BOOST_SIMD_SUPPORTS(cpu_)
          , T a0
          , T a1
          ) BOOST_NOEXCEPT
  {
    return is_ord(a0,a1)&&(a0!=a1);
  }

  template <typename T
            , typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE as_logical_t<T>
  is_lessgreater_( BOOST_SIMD_SUPPORTS(cpu_)
                 , std_tag const &
                 , T a0
                 , T a1
                 ) BOOST_NOEXCEPT
  {
    return std::islessgreater(a0, a1);
  }

} } }


#endif
