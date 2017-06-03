//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_DIVIDES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_DIVIDES_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{

 BOOST_FORCEINLINE pack<double,4,avx_> bitwise_and_( BOOST_SIMD_SUPPORTS(avx_)
                                                    , pack<double,4,avx_> const& a0
                                                    , pack<double,4,avx_> const& a1
                                                    ) BOOST_NOEXCEPT
  {
    return _mm256_div_pd(a0,a1);
  }

  BOOST_FORCEINLINE pack<float,8,avx_> bitwise_and_ ( BOOST_SIMD_SUPPORTS(avx_)
                                                    , pack<float,8,avx_> const& a0
                                                    , pack<float,8,avx_> const& a1
                                                    ) BOOST_NOEXCEPT
  {
    return _mm256_div_ps(a0,a1);
  }

} } }

#endif
