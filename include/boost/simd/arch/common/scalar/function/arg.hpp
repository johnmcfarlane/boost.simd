//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ARG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ARG_HPP_INCLUDED


#include <boost/simd/detail/pack.hpp>
#ifndef BOOST_SIMD_NO_NANS
#include <boost/simd/function/if_allbits_else.hpp>
#include <boost/simd/function/is_nan.hpp>
#endif
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T arg_(BOOST_SIMD_SUPPORTS(cpu_)
         , T const& a) BOOST_NOEXCEPT
  {
    return if_else_zero(is_negative(a),Pi<T>());
  }

  //================================================================================================
  // pedantic_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T arg_(BOOST_SIMD_SUPPORTS(cpu_)
         , pedantic_tag const&
         , T const& a) BOOST_NOEXCEPT
  {
    T r = if_else_zero(is_negative(a),Pi<T>());
#ifndef BOOST_SIMD_NO_NANS
    return if_allbits_else(is_nan(a),r);
#else
    return r;
#endif
  }

} } }


#endif
