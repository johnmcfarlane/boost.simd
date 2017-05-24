//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_BITWISE_XOR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_BITWISE_XOR_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template< typename T, std::size_t N
          , typename = typename std::enable_if<std::is_integral<T>::value>::type
          >
  BOOST_FORCEINLINE pack<T,N,avx_> bitwise_xor_( BOOST_SIMD_SUPPORTS(avx2_)
                                               , pack<T,N,avx_> const& a0
                                               , pack<T,N,avx_> const& a1
                                               ) BOOST_NOEXCEPT
  {
    return _mm256_xor_si256(a0, a1);
  }
} } }

#endif
