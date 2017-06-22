//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_NGEZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_NGEZ_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/is_not_greater_equal.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/meta/as_logical.hpp>

namespace boost { namespace simd { namespace detail
{
 // Native implementation

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_logical_t<pack<T,N>>
  s_is_ngez_ ( pack<T,N> const& a0
             , std::false_type
             ) BOOST_NOEXCEPT
  {
    return is_ltz(a0);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_logical_t<pack<T,N>>
  s_is_ngez_ ( pack<T,N> const& a0
             , std::true_type
             ) BOOST_NOEXCEPT
  {
    return is_not_greater_equal(a0, Zero(as(a0)));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_ngez_ ( BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N> const& a
                ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    s_is_ngez_(a, std::is_floating_point<T>())
  )

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_ngez_ ( BOOST_SIMD_SUPPORTS(simd_)
                , as_logical_t<pack<T,N>> const&
                ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    ( False<pack<T,N>>())
  )

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_ngez_ ( BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N,simd_emulation_> const& a
         ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
     map_to( simd::is_ngez, a)
  )


} } }

#endif

