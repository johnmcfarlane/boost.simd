//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ONEMINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ONEMINUS_HPP_INCLUDED

#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular cases
  template<typename T>
  BOOST_FORCEINLINE T oneminus_(BOOST_SIMD_SUPPORTS(cpu_), T const& a) BOOST_NOEXCEPT
  {
    return One<T>()-a; ;
  }

  //================================================================================================
  // saturated_ decorator
  template<typename T> BOOST_FORCEINLINE
  T soneminus_(T a
              , case_<0> const&) BOOST_NOEXCEPT //float
  {
    return One<T>()-a; ;
  }

  template<typename T> BOOST_FORCEINLINE
  T soneminus_(T a
              , case_<1> const&) BOOST_NOEXCEPT //signed int
  {
    return (a <= Valmin<T>()+One<T>()) ? Valmax<T>() : One<T>()-a;
  }

  template<typename T> BOOST_FORCEINLINE
  T soneminus_(T a,
               case_<2> const&) BOOST_NOEXCEPT // unsigned int
  {
    return !a;
  }

  template<typename T>
  BOOST_FORCEINLINE T oneminus_( BOOST_SIMD_SUPPORTS(cpu_)
                               , saturated_tag const&
                               , T const& a) BOOST_NOEXCEPT
  {
    return soneminus_(a, fsu_picker<T>{});
  }
} } }

#endif
