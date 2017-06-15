//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_INC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_INC_HPP_INCLUDED

#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/if_inc.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{

  //================================================================================================
  // regular cases
  template<typename T>
  BOOST_FORCEINLINE T inc_(BOOST_SIMD_SUPPORTS(cpu_), T const& a) BOOST_NOEXCEPT
  {
    return a+One<T>();
  }

  //================================================================================================
  // saturated_ incorator
  template<typename T> BOOST_FORCEINLINE
  T s_inc_( T a
          , std::true_type const&) BOOST_NOEXCEPT
  {
    return inc(a);
  }

  template<typename T> BOOST_FORCEINLINE
  T s_inc_( T a
          , std::false_type const&) BOOST_NOEXCEPT
  {
    return if_inc(is_not_equal(a, Valmax(as(a))), a);
  }

  template<typename T>
  BOOST_FORCEINLINE T
  inc_( BOOST_SIMD_SUPPORTS(cpu_)
      , saturated_tag const&, T a) BOOST_NOEXCEPT
  {
    return s_inc_(a, std::is_floating_point<T>{});
  }


} } }

#endif
