//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_INF_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_INF_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/false.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/is_equal.hpp>

namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto v_is_inf_ ( pack<T,N> const& a0
                 , std::true_type const &
                 ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    ((a0 & Inf(as(a0))) == Inf(as(a0)))
  )

    template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto v_is_inf_ ( pack<T,N> const&
                 , std::false_type const &
                 ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    (False<pack<T,N>>())
  )

    template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_inf_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T,N> const& a
               ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    v_is_inf_(a, std::is_floating_point<T>())
  )

  // Emulated implementation
    template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_inf_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T,N,simd_emulation_> const& a
               ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::is_inf, a)
  )

  // std decoator
    template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_inf_ ( BOOST_SIMD_SUPPORTS(simd_)
               , std_tag const &
               , pack<T,N> const& a
               ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( std_(simd::is_inf), a)
  )

} } }

#endif

