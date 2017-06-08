//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_FMA4_SIMD_FUNCTION_FMA_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_FMA4_SIMD_FUNCTION_FMA_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>

#if BOOST_HW_SIMD_X86_AMD_FMA4
namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<double,2,sse_> fma_( BOOST_SIMD_SUPPORTS(sse2_)
                                            , pack<double,2,sse_> const& a0
                                            , pack<double,2,sse_> const& a1
                                            , pack<double,2,sse_> const& a2
                                            ) BOOST_NOEXCEPT
  {
    return _mm_macc_pd(a0, a1, a2);
  }

  BOOST_FORCEINLINE pack<float,4,sse_> fma_( BOOST_SIMD_SUPPORTS(sse2_)
                                            , pack<float,4,sse_> const& a0
                                            , pack<float,4,sse_> const& a1
                                            , pack<float,4,sse_> const& a2
                                            ) BOOST_NOEXCEPT
  {
    return _mm_macc_ps(a0, a1, a2);
  }

   BOOST_FORCEINLINE pack<double,4,avx_> fma_( BOOST_SIMD_SUPPORTS(avx_)
                                            , pack<double,4,avx_> const& a0
                                            , pack<double,4,avx_> const& a1
                                            , pack<double,4,avx_> const& a2
                                            ) BOOST_NOEXCEPT
  {
    return _mm256_macc_pd(a0, a1, a2);
  }

  BOOST_FORCEINLINE pack<float,8,avx_> fma_( BOOST_SIMD_SUPPORTS(avx_)
                                            , pack<float,8,avx_> const& a0
                                            , pack<float,8,avx_> const& a1
                                            , pack<float,8,avx_> const& a2
                                            ) BOOST_NOEXCEPT
  {
    return _mm256_macc_ps(a0, a1, a2);
  }

  // pedantic
  BOOST_FORCEINLINE pack<double,2,sse_> fma_( BOOST_SIMD_SUPPORTS(sse2_)
                                            , const pedantic_tag &
                                            , pack<double,2,sse_> const& a0
                                            , pack<double,2,sse_> const& a1
                                            , pack<double,2,sse_> const& a2
                                            ) BOOST_NOEXCEPT
  {
    return _mm_macc_pd(a0, a1, a2);
  }

  BOOST_FORCEINLINE pack<float,4,sse_> fma_( BOOST_SIMD_SUPPORTS(sse2_)
                                            , const pedantic_tag &
                                            , pack<float,4,sse_> const& a0
                                            , pack<float,4,sse_> const& a1
                                            , pack<float,4,sse_> const& a2
                                            ) BOOST_NOEXCEPT
  {
    return _mm_macc_ps(a0, a1, a2);
  }

   BOOST_FORCEINLINE pack<double,4,avx_> fma_( BOOST_SIMD_SUPPORTS(avx_)
                                            , const pedantic_tag &
                                            , pack<double,4,avx_> const& a0
                                            , pack<double,4,avx_> const& a1
                                            , pack<double,4,avx_> const& a2
                                            ) BOOST_NOEXCEPT
  {
    return _mm256_macc_pd(a0, a1, a2);
  }

  BOOST_FORCEINLINE pack<float,8,avx_> fma_( BOOST_SIMD_SUPPORTS(avx_)
                                            , const pedantic_tag &
                                            , pack<float,8,avx_> const& a0
                                            , pack<float,8,avx_> const& a1
                                            , pack<float,8,avx_> const& a2
                                            ) BOOST_NOEXCEPT
  {
    return _mm256_macc_ps(a0, a1, a2);
  }


} } }
#endif


#endif
