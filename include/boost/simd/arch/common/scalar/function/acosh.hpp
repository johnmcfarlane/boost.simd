//==================================================================================================
/*!
  @file
  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ACOSH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ACOSH_HPP_INCLUDED

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

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T acosh_(BOOST_SIMD_SUPPORTS(cpu_)
         , T const& a0) BOOST_NOEXCEPT
  {
      auto t = dec(a0);
      if(BOOST_LIKELY(t <= Oneotwoeps<T>()))
        return log1p(t+bs::sqrt(t+t+sqr(t)));
      else
        return log(t)+Log_2<T>();
  }

  //================================================================================================
  // std_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T acosh_(BOOST_SIMD_SUPPORTS(cpu_)
         , std_tag const&
         , T const& a) BOOST_NOEXCEPT
  {
    return std::acosh(a);
  }

} } }

#endif
