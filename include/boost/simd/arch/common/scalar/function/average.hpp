//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_AVERAGE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_AVERAGE_HPP_INCLUDED

#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T>
  BOOST_FORCEINLINE T
  saverage_( T a0
           , T a1, std::true_type const &) BOOST_NOEXCEPT
  {
    return fma(a0,Half(as(a0)),a1*Half(as(a0)));
  }

  template<typename T>
  BOOST_FORCEINLINE T
  saverage_( T a0
           , T a1, std::false_type const &) BOOST_NOEXCEPT
  {
    return  bitwise_and(a0, a1)+shift_right(bitwise_xor(a0, a1),1);
  }
  template<typename T>
  BOOST_FORCEINLINE T
  average_(BOOST_SIMD_SUPPORTS(cpu_)
          , T a0
          , T a1) BOOST_NOEXCEPT
  {
    return saverage_(a0, a1, std::is_floating_point<T>());
  }

} } }


#endif
