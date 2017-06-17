//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMPLEMENT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMPLEMENT_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/logical_xor.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/constant/true.hpp>

namespace boost { namespace simd { namespace detail
{
 // Native implementations
   template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> complement_ (BOOST_SIMD_SUPPORTS(simd_), pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return bitwise_xor(simd::Allbits(as(a0)), a0);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto complement_ (BOOST_SIMD_SUPPORTS(simd_), pack<logical<T>,N> const& a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    logical_xor(simd::True(as(a0)), a0)
  )

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_> complement__ ( BOOST_SIMD_SUPPORTS(simd_)
                                                           , pack<T,N,simd_emulation_> const& a
                                                           ) BOOST_NOEXCEPT
  {
    return map_to(simd::complement, a);
  }
} } }

#endif
