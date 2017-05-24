//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_BITWISE_NOTAND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_BITWISE_NOTAND_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<float,8,avx_> bitwise_notand_ ( BOOST_SIMD_SUPPORTS(avx_)
                                                       , pack<float,8,avx_> const& a0
                                                       , pack<float,8,avx_> const& a1
                                                       ) BOOST_NOEXCEPT
  {
    return _mm256_andnot_ps(a0, a1);
  }

  BOOST_FORCEINLINE pack<double,4,avx_> bitwise_notand_( BOOST_SIMD_SUPPORTS(avx_)
                                                       , pack<double,4,avx_> const& a0
                                                       , pack<double,4,avx_> const& a1
                                                       ) BOOST_NOEXCEPT
  {
    return _mm256_andnot_pd(a0, a1);
  }

  template< typename T, std::size_t N
            , typename = typename std::enable_if< std::is_integral<T>::value >::type
  >
  BOOST_FORCEINLINE pack<T, N, avx_> bitwise_notand_ ( BOOST_SIMD_SUPPORTS(avx_)
                                                     , pack<T,N,avx_> const& a0
                                                     , pack<T,N,avx_> const& a1
                                                     ) BOOST_NOEXCEPT
  {
    return _mm256_castps_si256(_mm256_andnot_ps( _mm256_castsi256_ps(a0)
                                               , _mm256_castsi256_ps(a1)
                                               )
                              );
  }
} } }

#endif
