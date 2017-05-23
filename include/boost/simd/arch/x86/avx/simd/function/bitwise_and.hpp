//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<float,8> avx_bitwise_and_( pack<float,8> const& a0
                                                  , pack<float,8> const& a1
                                                  ) BOOST_NOEXCEPT
  {
    return _mm256_and_pd(a0, a1);
  }
  BOOST_FORCEINLINE pack<double,4> avx_bitwise_and_( pack<double,4> const& a0
                                                   , pack<double,4> const& a1
                                                   ) BOOST_NOEXCEPT
  {
    return _mm256_and_pd(a0, a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T, N, avx_> avx_bitwise_and_ ( pack<T,N,avx_> const& a0
                                                      , pack<T,N,avx_> const& a1
                                                      ) BOOST_NOEXCEPT
  {
      return _mm256_castps_si256(_mm256_and_ps( _mm256_castsi256_ps(a0)
                                              , _mm256_castsi256_ps(a1)
                                              )
                                );
  }

  template<typename T1, typename T2, std::size_t N, std::size_t M
           , typename = typename std::enable_if<sizeof(T1)*N == sizeof(T2)*M>::type>
  BOOST_FORCEINLINE pack<T,N, avx_> bitwise_and_ ( BOOST_SIMD_SUPPORTS(avx_)
                                                 , pack<T1,N,avx_> const& a
                                                 , pack<T2,M,avx_> const& b
                                                 ) BOOST_NOEXCEPT
  {
    using Type1 =  pack<T1,N,avx_>;
    return avx_bitwise_and(a, simd::bitwise_cast<Type1>(b));
  }

} } }

#endif
