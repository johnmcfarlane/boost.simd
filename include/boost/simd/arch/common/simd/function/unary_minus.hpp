//==================================================================================================
/**

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_UNARY_MINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_UNARY_MINUS_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/zero.hpp>

namespace boost { namespace simd { namespace detail
{

  //================================================================================================
  // regular case
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vum_(pack<T,N> a, detail::case_<0> const&) BOOST_NOEXCEPT
  {
    return bitwise_xor(Mzero(as(a)),a);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vum_(pack<T,N> a, detail::case_<1> const&) BOOST_NOEXCEPT
  {
    return Zero(as(a)) - a;;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vum_(pack<T,N> a, detail::case_<2> const&) BOOST_NOEXCEPT
  {
    return Zero(as(a)) - a;;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> unary_minus_(BOOST_SIMD_SUPPORTS(simd_)
                        , pack<T,N> a) BOOST_NOEXCEPT
  {
    return vum_(a, um_picker<T>());
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> unary_minus_ ( BOOST_SIMD_SUPPORTS(simd_)
                                         , pack<T,N,simd_emulation_> const& a
                                         ) BOOST_NOEXCEPT
  {
    return map_to(simd::unary_minus, a);
  }

  //================================================================================================
  // saturated_ decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vums_(pack<T,N> a, detail::case_<0> const&) BOOST_NOEXCEPT
  {
    return bitwise_xor(Mzero(as(a)),a);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vums_(pack<T,N> a, detail::case_<1> const&) BOOST_NOEXCEPT
  {
    using p_t =  pack<T, N>;
    return if_else(a == Valmin<p_t>(),Valmax<p_t>(),unary_minus(a));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vums_(pack<T,N> a, detail::case_<2> const&) BOOST_NOEXCEPT
  {
    using p_t =  pack<T, N>;
    return if_else(a == Valmin<p_t>(),Valmax<p_t>(),unary_minus(a));
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> unary_minus_(BOOST_SIMD_SUPPORTS(simd_)
                        , saturated_tag const &
                        , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return vums_(a,um_picker<T>{});
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> unary_minus_ ( BOOST_SIMD_SUPPORTS(simd_)
                                         , saturated_tag const &
                                         , pack<T,N,simd_emulation_> const& a
                                         ) BOOST_NOEXCEPT
  {
    return map_to(saturated_(simd::unary_minus), a);
  }

} } }

#endif
