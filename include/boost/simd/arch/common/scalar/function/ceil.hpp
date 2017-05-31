//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CEIL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CEIL_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/function/std.hpp>
#include <type_traits>
#include <boost/config.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  float ceil_(BOOST_SIMD_SUPPORTS(cpu_)
             , float a) BOOST_NOEXCEPT
  {
    #ifdef BOOST_SIMD_HAS_FLOORF
      return ::ceilf(a0);
    #else
      return std::ceil(a);
    #endif
  }

  BOOST_FORCEINLINE
  double ceil_(BOOST_SIMD_SUPPORTS(cpu_)
              , double a) BOOST_NOEXCEPT
  {
    return std::ceil(a);
  }

 template<typename T
          , typename = typename std::enable_if<std::is_integral<T>::value>::type
 >
 BOOST_FORCEINLINE
  T ceil_(BOOST_SIMD_SUPPORTS(cpu_)
              , T a) BOOST_NOEXCEPT
  {
    return a;
  }

  //std_ decorator
  template<typename T >
  BOOST_FORCEINLINE
  T ceil_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const &
         , T a) BOOST_NOEXCEPT
  {
   return  T(std::ceil(a));
  }

} } }

#endif
