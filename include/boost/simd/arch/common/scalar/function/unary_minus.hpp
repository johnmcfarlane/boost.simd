//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_UNARY_MINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_UNARY_MINUS_HPP_INCLUDED

#ifdef BOOST_MSVC
  #pragma warning(disable: 4146) // unary minus applied to unsigned
  #pragma warning(push)
#endif
#include <boost/config.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>

namespace boost { namespace simd { namespace detail
{

  //================================================================================================
  // regular case
  template<typename T>
  BOOST_FORCEINLINE T unary_minus_(BOOST_SIMD_SUPPORTS(cpu_)
                                  , T a) BOOST_NOEXCEPT
  {
    return -a;
  }

  //================================================================================================
  // saturated_ decorator
  template<typename T>
  BOOST_FORCEINLINE T sunary_minus_(T a, detail::case_<0> const&) BOOST_NOEXCEPT //floating
  {
    return -a;
  }

  template<typename T>
  BOOST_FORCEINLINE T sunary_minus_(T a, detail::case_<1> const&) BOOST_NOEXCEPT // signed
  {
     return a == Valmin<T>() ? Valmax<T>() : -a;
  }

  template<typename T>
  BOOST_FORCEINLINE T sunary_minus_(T a, detail::case_<2> const&) BOOST_NOEXCEPT //unsigned
  {
    return Zero<T>();
  }
  template<typename T>
  BOOST_FORCEINLINE T unary_minus_(BOOST_SIMD_SUPPORTS(cpu_)
                                  ,  saturated_tag const &
                                  , T a) BOOST_NOEXCEPT
  {
    return sunary_minus_(a, fsu_picker<T>{});
  }

} } }

#ifdef BOOST_MSVC
  #pragma warning(pop)
#endif

#endif
