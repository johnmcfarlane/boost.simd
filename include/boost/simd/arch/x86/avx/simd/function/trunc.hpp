//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_TRUNC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_TRUNC_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<float,8,avx_> trunc_ ( BOOST_SIMD_SUPPORTS(avx_)
                                              , pack<float,8,avx_> const& a0
                                              ) BOOST_NOEXCEPT
  {
    return _mm256_round_ps(a0, _MM_FROUND_TO_ZERO);
  }

  BOOST_FORCEINLINE pack<double,4,avx_> trunc_ ( BOOST_SIMD_SUPPORTS(avx_)
                                               , pack<double,4,avx_> const& a0
                                               ) BOOST_NOEXCEPT
  {
    return _mm256_round_pd(a0, _MM_FROUND_TO_ZERO);
  }

} } }

#endif
