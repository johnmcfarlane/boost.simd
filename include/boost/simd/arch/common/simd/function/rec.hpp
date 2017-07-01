//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REC_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/if_one_else_zero.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{

  //================================================================================================
  // regular case
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  vrec_(pack<T,N> a, detail::case_<0> const&) BOOST_NOEXCEPT
  {
    /// rec for floating types: take all version when no better exists reverting to division
    return One(as(a))/a;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  vrec_(pack<T,N> a0, detail::case_<1> const&) BOOST_NOEXCEPT
  {
    // rec on signed integral values
    return if_else(a0, if_else_zero(bs::abs(a0) == One(as(a0)), a0), Valmax(as(a0)));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  vrec_(pack<T,N> a0, detail::case_<2> const&) BOOST_NOEXCEPT
  {
    // rec on unsigned values is identity
    return if_else_allbits(a0, if_one_else_zero(a0 == One(as(a0))));
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> rec_(BOOST_SIMD_SUPPORTS(simd_), pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return vrec_(a,fsu_picker<T>{});
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_> rec_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                   , pack<T,N,simd_emulation_> const& a
                                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::rec, a);
  }

  // raw implementation if no better
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  rec_ ( BOOST_SIMD_SUPPORTS(simd_)
       , raw_tag const &
       , pack<T,N> const& a
       ) BOOST_NOEXCEPT
  {
    return rec(a);
  }

} } }

#endif
