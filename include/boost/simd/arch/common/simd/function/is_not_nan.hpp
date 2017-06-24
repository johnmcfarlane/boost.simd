//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_NOT_NAN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_NOT_NAN_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/is_ord.hpp>

namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto v_is_not_nan_ ( pack<T,N> const& a0
                 , std::true_type const &
                 ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    (is_ord(a0, a0))
  )

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto v_is_not_nan_ ( pack<T,N> const&
                 , std::false_type const &
                 ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    (True<pack<T,N>>())
  )

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_not_nan_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T,N> const& a
               ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    v_is_not_nan_(a, std::is_floating_point<T>())
  )

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_not_nan_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T,N,simd_emulation_> const& a
               ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::is_not_nan, a)
  )

} } }

#endif

