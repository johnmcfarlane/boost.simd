//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEXTPOW2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEXTPOW2_HPP_INCLUDED

#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/ffs.hpp>
#include <boost/simd/function/ifrexp.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/reversebits.hpp>
#include <boost/config.hpp>
#include <tuple>
#include <boost/simd/detail/meta/fsu_picker.hpp>
#include <boost/simd/detail/meta/convert_helpers>

namespace boost { namespace simd { namespace detail
{
 //================================================================================================
  // regular cases
  template<typename T>
  BOOST_FORCEINLINE si_t<T>
  s_nextpow2_( T x
              , detail::case_<0> const&) BOOST_NOEXCEPT
  {
    T m;
    si_t<T> p;
    std::tie(m, p) = pedantic_(ifrexp)(simd::abs(a0));
    return (m == Half<T>()) ? saturated_(dec)(p) :  p;
  }

  template<typename T>
  BOOST_FORCEINLINE si_t<T>
  s_nextpow2_( T a0
              , detail::case_<1> const&) BOOST_NOEXCEPT
  {
    if (!a0) return a0;
    return sizeof(T)*8-ffs(reversebits(saturated_(abs)(a0)));
  }

  template<typename T>
  BOOST_FORCEINLINE si_t<T>
  s_nextpow2_(T a0
              , detail::case_<2> const&) BOOST_NOEXCEPT
  {
    if (!a0) return a0;
    return sizeof(T)*8-ffs(reversebits(a0));
  }

  template<typename T>
  BOOST_FORCEINLINE si_t<T>
  nextpow2_(BOOST_SIMD_SUPPORTS(cpu_)
             , T const& a) BOOST_NOEXCEPT
  {
    return s_nextpow2_(a, fsu_picker<T>{});
  }

} } }


#endif

