//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_DEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_DEC_HPP_INCLUDED

#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/function/is_not_equal.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/if_dec.hpp>
#include <type_traits>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{

  //================================================================================================
  // regular cases
  template<typename T>
  BOOST_FORCEINLINE T dec_(BOOST_SIMD_SUPPORTS(cpu_), T const& a) BOOST_NOEXCEPT
  {
    return a-One<T>();
  }

  //================================================================================================
  // saturated_ decorator
  template<typename T> BOOST_FORCEINLINE T sdec_( T a
                                                , std::true_type const&) BOOST_NOEXCEPT
  {
    return dec(a);
  }

  template<typename T> BOOST_FORCEINLINE T sdec_( T a
                                                , std::false_type const&) BOOST_NOEXCEPT
  {
    return if_dec(is_not_equal(a, Valmin(as(a))), a);
  }

  template<typename T>
  BOOST_FORCEINLINE T dec_( BOOST_SIMD_SUPPORTS(cpu_)
                          , saturated_tag const&, T a) BOOST_NOEXCEPT
  {
    return sdec_(a, std::is_floating_point<T>{});
  }

} } }

#endif
