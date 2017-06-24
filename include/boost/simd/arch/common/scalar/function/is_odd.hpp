//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_ODD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_ODD_HPP_INCLUDED

#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/is_even.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
   BOOST_FORCEINLINE bool
   is_odd_ ( BOOST_SIMD_SUPPORTS(cpu_)
                , bool a0
                ) BOOST_NOEXCEPT
   {
     return a0;
   }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_odd_( T a0
            , std::true_type const &
            ) BOOST_NOEXCEPT
  {
    return is_even(dec(a0));
  }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_odd_( T a0
            , std::false_type const &
            ) BOOST_NOEXCEPT
  {
    return (bitwise_and(a0,One<T>()) != 0);
  }

  template <typename T,
            typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE as_logical_t<T>
  is_odd_( BOOST_SIMD_SUPPORTS(cpu_)
              , T a0
              ) BOOST_NOEXCEPT
  {
    return s_is_odd_(a0, std::is_floating_point<T>());
  }

} } }

#endif
