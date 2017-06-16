//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SQR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SQR_HPP_INCLUDED

#include <boost/simd/constant/sqrtvalmax.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular cases
  template<typename T>
  BOOST_FORCEINLINE
  T sqr_(BOOST_SIMD_SUPPORTS(cpu_)
        , T a) BOOST_NOEXCEPT
  {
    return a*a;
  }

  //================================================================================================
  // saturated_ decorator
  template<typename T>
  BOOST_FORCEINLINE
  T ssqr_(T a0
         , std::false_type const&) BOOST_NOEXCEPT
  {
    return saturated_(abs)(a0) > Sqrtvalmax<T>() ? Valmax<T>() : sqr(a0);
  }

  template<typename T>
  BOOST_FORCEINLINE
  T ssqr_(T a0
         , std::true_type const&) BOOST_NOEXCEPT
  {
    return sqr(a0);
  }

  template<typename T>
  BOOST_FORCEINLINE T sqr_( BOOST_SIMD_SUPPORTS(cpu_)
                          , saturated_tag const&
                          , T const& a) BOOST_NOEXCEPT
  {
    return ssqr_(a, std::is_floating_point<T>());
  }

} } }

#endif
