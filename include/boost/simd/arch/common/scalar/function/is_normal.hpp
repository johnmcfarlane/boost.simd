//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_NORMAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_IS_NORMAL_HPP_INCLUDED

#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/is_not_denormal.hpp>
#include <boost/simd/function/is_finite.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
   BOOST_FORCEINLINE bool
   is_normal_ ( BOOST_SIMD_SUPPORTS(cpu_)
                , bool a0
                ) BOOST_NOEXCEPT
   {
     return a0;
   }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_normal_( T a0
            , std::true_type const &
            ) BOOST_NOEXCEPT
  {
    return  is_finite(a0)&&is_nez(a0)&&is_not_denormal(a0);
  }

  template <typename T>
  BOOST_FORCEINLINE as_logical_t<T>
  s_is_normal_( T a0
            , std::false_type const &
            ) BOOST_NOEXCEPT
  {
    return is_nez(a0);
  }

  template <typename T,
            typename =  typename std::enable_if<std::is_arithmetic<T>::value>
  >
  BOOST_FORCEINLINE as_logical_t<T>
  is_normal_( BOOST_SIMD_SUPPORTS(cpu_)
              , T a0
              ) BOOST_NOEXCEPT
  {
    return s_is_normal_(a0, std::is_floating_point<T>());
  }

 template <typename T,
            typename =  typename std::enable_if<std::is_floating_point<T>::value>
  >
  BOOST_FORCEINLINE as_logical_t<T>
  is_normal_( BOOST_SIMD_SUPPORTS(cpu_)
              , std_tag const &
              , T a0
              ) BOOST_NOEXCEPT
  {
    return std::isnormal(a0);
  }

} } }


#endif
