//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<double,4,avx_>
  is_equal_( BOOST_SIMD_SUPPORTS(avx_)
           , pack<double,4,avx_> const& a0
           , pack<double,4,avx_> const& a1
           ) BOOST_NOEXCEPT
  {
    return _mm256_cmp_pd(a0,a1,_CMP_EQ_OQ);
  }

  BOOST_FORCEINLINE pack<float,8,avx_>
  is_equal_ ( BOOST_SIMD_SUPPORTS(avx_)
            , pack<float,8,avx_> const& a0
            , pack<float,8,avx_> const& a1
            ) BOOST_NOEXCEPT
  {
    return _mm256_cmp_ps(a0,a1,_CMP_EQ_OQ);
  }

  BOOST_FORCEINLINE pack<double,2,sse_>
  is_equal_( BOOST_SIMD_SUPPORTS(sse_)
           , pack<double,2,sse_> const& a0
           , pack<double,2,sse_> const& a1
           ) BOOST_NOEXCEPT
  {
    return _mm_cmp_pd(a0,a1,_CMP_EQ_OQ);
  }

  BOOST_FORCEINLINE pack<float,4,sse_>
  is_equal_ ( BOOST_SIMD_SUPPORTS(sse_)
            , pack<float,4,sse_> const& a0
            , pack<float,4,sse_> const& a1
            ) BOOST_NOEXCEPT
  {
    return _mm_cmp_ps(a0,a1,_CMP_EQ_OQ);
  }

} } }

#endif
