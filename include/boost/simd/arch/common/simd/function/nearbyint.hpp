//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NEARBYINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NEARBYINT_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/raw.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vnearbyint_( pack<T,N> const& a0, std::true_type const &) BOOST_NOEXCEPT
  {
    using p_t =  pack<T,N>;
    p_t s   = bitofsign(a0);
    p_t v   = bitwise_xor(a0, s);
    p_t t2n = bs::Twotonmb<p_t>();
    p_t d0  = v+t2n;
    return bitwise_xor(if_else(is_less(v,t2n),d0-t2n,v), s);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vnearbyint_( pack<T,N> const& a0, std::false_type const &) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> nearbyint_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return vnearbyint_(a0, std::is_floating_point<T>());
  }

 // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> nearbyint_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::nearbyint, a);
  }

  //================================================================================================
  // std decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto nearbyint_(BOOST_SIMD_SUPPORTS(simd_)
            , std_tag const&
            , pack<T,N> const& a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to(std_(simd::nearbyint), a0)
  )

  //================================================================================================
  // raw decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto nearbyint_(BOOST_SIMD_SUPPORTS(simd_)
            , raw_tag const&
            , pack<T,N> const& a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    simd::nearbyint(a0)
  )
} } }

#endif
