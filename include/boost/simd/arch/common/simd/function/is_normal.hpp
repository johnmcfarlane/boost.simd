//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_NORMAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_NORMAL_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/is_not_denormal.hpp>
#include <boost/simd/function/is_finite.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto v_is_normal_ ( pack<T,N> const& a0
                  , std::true_type const &
                  ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    logical_and(logical_and(is_finite(a0), is_nez(a0)), is_not_denormal(a0))
  )

    template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto v_is_normal_ ( pack<T,N> const& a0
                  , std::false_type const &
                  ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    is_nez(a0)
  )

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_normal_ ( BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N> const& a
                ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    v_is_normal_(a, std::is_floating_point<T>())
  )

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_normal_ ( BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N,simd_emulation_> const& a
                ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::is_normal, a)
  )

  // std implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_normal_ ( BOOST_SIMD_SUPPORTS(simd_)
                  , std_tag const &
                  , pack<T,N> const& a
                  ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( std_(simd::is_normal), a)
  )
    } } }


#endif
