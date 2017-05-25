//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ACOSH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ACOSH_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/oneotwoeps.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/log1p.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <boost/simd/function/inc.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> acosh_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    auto t = dec(a);
    auto test = is_greater(t,Oneotwoeps(as(a)));
    auto z = if_else(test, a, t+sqrt(t+t+sqr(t)));
    return if_plus(test, log1p(z), Log_2(as(a)));
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> acosh_ ( BOOST_SIMD_SUPPORTS(simd_)
                                   , pack<T,N,simd_emulation_> const& a
                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::acosh, a);
  }

  //================================================================================================
  // std_ decorator
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<T,N,X> acosh_( BOOST_SIMD_SUPPORTS(simd_)
                   , std_tag const&
                   , pack<T,N,X> const& a) BOOST_NOEXCEPT
  {
    return map_to(std_(simd::acosh), a);
  }

} } }

#endif
