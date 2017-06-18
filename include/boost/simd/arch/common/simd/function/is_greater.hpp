//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_GREATER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_GREATER_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{

  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE  auto
  is_greater_ ( BOOST_SIMD_SUPPORTS(simd_)
              , pack<T, N, X> const& a
              , pack<T, N, X> const& b
              ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::is_greater, a, b)
  )

 // mixed implementation
  template< typename T, std::size_t N, typename X, typename U
          , typename =  std::enable_if<std::is_convertible<U, T>::value>
  >
  BOOST_FORCEINLINE auto
  is_greater_ ( BOOST_SIMD_SUPPORTS(simd_)
            , pack<T,N,X> const& a
            , U b
            ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::is_greater, a, pack<T,N,X>(b))
  )

  template< typename T, std::size_t N, typename X, typename U
          , typename =  std::enable_if<std::is_convertible<U, T>::value>
  >
  BOOST_FORCEINLINE auto
  is_greater_ ( BOOST_SIMD_SUPPORTS(simd_)
            , U a
            , pack<T,N,X> const& b
            ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::is_greater, pack<T,N,X>(a), b)
  )

} } }

#endif
