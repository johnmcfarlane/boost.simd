//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_LESS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_LESS_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{

  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE  auto
  is_less_ ( BOOST_SIMD_SUPPORTS(simd_)
              , pack<T, N, X> const& a
              , pack<T, N, X> const& b
              ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::is_less, a, b)
  )

  // mixed implementation
  template< typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE typename std::enable_if<std::is_convertible<U, T>::value
                                            , as_logical_t< pack<T,N>>>::type
  is_less_ ( BOOST_SIMD_SUPPORTS(simd_)
            , pack<T,N> const& a
            , U b
            ) BOOST_NOEXCEPT
  {
    return is_less(a, pack<T,N>(b));
  }


  template< typename T, std::size_t N, typename U >
  BOOST_FORCEINLINE typename std::enable_if<std::is_convertible<U, T>::value
                                            , as_logical_t< pack<T,N>>>::type
  is_less_ ( BOOST_SIMD_SUPPORTS(simd_)
            , U a
            , pack<T,N> const& b
            ) BOOST_NOEXCEPT
  {
    return is_less(pack<T,N>(a), b);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_logical_t<pack<T, N, simd_emulation_>>
  is_less_ ( BOOST_SIMD_SUPPORTS(simd_)
              , pack<T,N,simd_emulation_> const& a
              , pack<T,N,simd_emulation_> const& b
              ) BOOST_NOEXCEPT
  {
    return map_to( simd::is_less, a, b);
  }

} } }

#endif
