//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_PREDECESSOR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_PREDECESSOR_HPP_INCLUDED

#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/function/bitfloating.hpp>
#include <boost/simd/function/bitinteger.hpp>
#include <boost/simd/function/is_gez.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/assert.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  // one parameter
  template<typename T>
  BOOST_FORCEINLINE
  T s_predecessor_( T a0
                  , std::true_type const &) BOOST_NOEXCEPT
  {
    return (is_nan(a0)) ? a0 : bitfloating(saturated_(dec)(bitinteger(a0)));
  }

  template<typename T >
  BOOST_FORCEINLINE
  T s_predecessor_( T a0
                  , std::false_type) BOOST_NOEXCEPT
  {
    return saturated_(dec)(a0);
  }

  template<typename T>
  BOOST_FORCEINLINE
  T predecessor_(BOOST_SIMD_SUPPORTS(cpu_)
                , T a) BOOST_NOEXCEPT
  {
    return s_predecessor_(a, std::is_floating_point<T>());
  }

  // two parameters
  template<typename T, typename U>
  BOOST_FORCEINLINE T
  spredecessor_( T a0
               , U a1
               , std::true_type const &) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(is_gez(a1), "predecessor rank must be non negative");
    return  (is_nan(a0)) ? a0 : bitfloating(saturated_(minus)(bitinteger(a0), si_t<T>(a1)));
  }

  template<typename T, typename U>
  BOOST_FORCEINLINE T
  spredecessor_( T a0
               , U a1
               , std::false_type const &) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(is_gez(a1), "predecessor rank must be non negative");
    return (Valmin<T>()+a1 > a0) ? Valmin<T>() : a0-a1;
  }

  template<typename T, typename U,
           typename = typename std::enable_if<is_integral<U>::value>
  >
  BOOST_FORCEINLINE T
  predecessor_(BOOST_SIMD_SUPPORTS(cpu_)
              , T a0
              , U a1) BOOST_NOEXCEPT
  {
    return spredecessor_(a0, a1, std::is_floating_point<T>());
  }

} } }


#endif
