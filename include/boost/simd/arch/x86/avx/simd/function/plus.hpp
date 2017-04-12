//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_PLUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_PLUS_HPP_INCLUDED

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<double,4> plus_( BOOST_SIMD_SUPPORTS(avx_)
                                        , pack<double,4> const& a0, pack<double,4> const& a1
                                        ) BOOST_NOEXCEPT
  {
    return _mm256_add_pd(a0,a1);
  }

  BOOST_FORCEINLINE pack<float,8> plus_ ( BOOST_SIMD_SUPPORTS(avx_)
                                        , pack<float,8> const& a0, pack<float,8> const& a1
                                        ) BOOST_NOEXCEPT
  {
    return _mm256_add_ps(a0,a1);
  }
} } }

#endif
