//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_LTZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_LTZ_HPP_INCLUDED

#include <boost/simd/function/is_less.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/constant/false.hpp>
#include <boost/simd/constant/zero.hpp>

namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto v_is_ltz_ ( pack<T,N> const& a0
                 , std::false_type const &
                 ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    is_less(a0, Zero(as(a0)))
  )

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto v_is_ltz_ ( pack<T,N> const&
                 , std::true_type const &
                 ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    (False<pack<T,N>>())
  )

    template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_ltz_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T,N> const& a
               ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    v_is_ltz_(a, std::is_unsigned<T>())
  )

  // Emulated implementation
    template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_ltz_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T,N,simd_emulation_> const& a
               ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::is_ltz, a)
  )

} } }

#endif
