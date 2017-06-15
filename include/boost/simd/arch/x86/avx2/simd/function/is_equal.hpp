//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED

#include <type_traits>
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T
           , typename = typename std::enable_if<std::is_integral<T>::value>::type
  >
  BOOST_FORCEINLINE bs::as_logical_t<pack<T,4,avx_>> is_equal_( BOOST_SIMD_SUPPORTS(avx_)
                                                              , pack<T,4,avx_> const& a0
                                                              , pack<T,4,avx_> const& a1
                                                              ) BOOST_NOEXCEPT
  {
    return _mm256_cmpeq_epi64(a0,a1);
  }

  template<typename T
           , typename = typename std::enable_if<std::is_integral<T>::value>::type
  >
  BOOST_FORCEINLINE bs::as_logical_t<pack<T,8,avx_>> is_equal_ ( BOOST_SIMD_SUPPORTS(avx_)
                                                               , pack<T,8,avx_> const& a0
                                                               , pack<T,8,avx_> const& a1
                                                               ) BOOST_NOEXCEPT
  {
    return _mm256_cmpeq_epi32(a0,a1);
  }

  template<typename T>
  BOOST_FORCEINLINE bs::as_logical_t<pack<T,16,avx_>> is_equal_ ( BOOST_SIMD_SUPPORTS(avx_)
                                                                , pack<T,16,avx_> const& a0
                                                                , pack<T,16,avx_> const& a1
                                                                ) BOOST_NOEXCEPT
  {
    return _mm256_cmpeq_epi16(a0,a1);
  }

  template<typename T>
  BOOST_FORCEINLINE bs::as_logical_t<pack<T,32,avx_>> is_equal_ ( BOOST_SIMD_SUPPORTS(avx_)
                                                                , pack<T,32,avx_> const& a0
                                                                , pack<T,32,avx_> const& a1
                                                                ) BOOST_NOEXCEPT
  {
    return _mm256_cmpeq_epi8(a0,a1);
  }

} } }

#endif
