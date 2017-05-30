//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ABS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ABS_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/function/bitwise_notand.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/detail/constant/maxleftshift.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>

namespace boost { namespace simd { namespace detail
{
  namespace bs = boost::simd;

  //================================================================================================
  // regular case
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> vabs_(pack<T,N> a, detail::case_<0> const&) BOOST_NOEXCEPT
  {
    // abs on real values cleans the sign bit
    return bitwise_notand(Mzero(as(a)),a);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> vabs_(pack<T,N>a, detail::case_<1> const&) BOOST_NOEXCEPT
  {
  // abs on signed integral values
    auto const s = shift_right(a, Maxleftshift<T>());
    return (a+s)^s;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> vabs_(pack<T,N> a, detail::case_<2> const&) BOOST_NOEXCEPT
  {
    // abs on unsigned values is identity
    return a;
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> abs_(BOOST_SIMD_SUPPORTS(simd_), pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return vabs_(a,fsu_picker<T>{});
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_> abs_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                   , pack<T,N,simd_emulation_> const& a
                                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::abs, a);
  }

  //================================================================================================
  // saturated_ decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> svabs_(pack<T,N> a, detail::case_<0> const&) BOOST_NOEXCEPT
  {
    // saturated abs on real values is merely abs
    return bs::abs(a);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> svabs_(pack<T,N> a, detail::case_<1> const&) BOOST_NOEXCEPT
  {
    // saturated abs on signed integral values takes care of Valmin
    return if_else(a == Valmin(as(a)), Valmax(as(a)), bs::abs(a));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> svabs_(pack<T,N> a, detail::case_<2> const&) BOOST_NOEXCEPT
  {
    // saturated abs on unsigned values is identity
    return a;
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> abs_ (BOOST_SIMD_SUPPORTS(simd_), saturated_tag const&, pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return svabs_(a,fsu_picker<T>{});
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_> abs_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                   , saturated_tag const&
                                                   , pack<T,N,simd_emulation_> const& a
                                                   ) BOOST_NOEXCEPT
  {
    return map_to(saturated_(simd::abs), a);
  }

  //================================================================================================
  // std_ decorator
  template<typename T, std::size_t N, typename X> BOOST_FORCEINLINE
  pack<T,N,X> abs_( BOOST_SIMD_SUPPORTS(simd_), std_tag const&, pack<T,N,X> const& a) BOOST_NOEXCEPT
  {
    return map_to(std_(simd::abs), a);
  }
} } }

#endif
