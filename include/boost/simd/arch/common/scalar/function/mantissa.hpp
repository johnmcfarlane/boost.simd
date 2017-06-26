//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MANTISSA_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MANTISSA_HPP_INCLUDED

#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/function/is_invalid.hpp>
#endif
#include <boost/simd/detail/constant/mantissamask.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T smantissa_( T a0
              , std::true_type const &) BOOST_NOEXCEPT
  {
    if(!a0) return a0;
#ifndef BOOST_SIMD_NO_INVALIDS
    if(is_invalid(a0)) return a0;
#endif
    return bitwise_or(bitwise_and(a0,Mantissamask<T>()),One<T>());
  }

  template<typename T >
  BOOST_FORCEINLINE
  T smantissa_( T a0
              , std::false_type) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T>
  BOOST_FORCEINLINE
  T mantissa_(BOOST_SIMD_SUPPORTS(cpu_)
             , T a) BOOST_NOEXCEPT
  {
    return smantissa_(a, std::is_floating_point<T>());
  }

} } }

#endif

