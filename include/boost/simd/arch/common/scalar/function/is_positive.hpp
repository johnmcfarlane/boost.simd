//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_POSITIVE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_POSITIVE_HPP_INCLUDED

#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/sbits.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/is_gez.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
   BOOST_FORCEINLINE bool
   is_positive_ ( BOOST_SIMD_SUPPORTS(cpu_)
                , bool
                ) BOOST_NOEXCEPT
   {
     return true;
   }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_positive_( T a0
            , std::true_type const &
            ) BOOST_NOEXCEPT
  {
    return is_gez(sbits(a0)).value();
  }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_positive_( T a0
            , std::false_type const &
            ) BOOST_NOEXCEPT
  {
    return is_gez(a0);
  }

  template <typename T,
            typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE as_logical_t<T>
  is_positive_( BOOST_SIMD_SUPPORTS(cpu_)
              , T a0
              ) BOOST_NOEXCEPT
  {
    return s_is_positive_(a0, std::is_floating_point<T>());
  }

} } }


#endif
