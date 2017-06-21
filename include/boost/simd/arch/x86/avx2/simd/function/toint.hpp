//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_TOINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_TOINT_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_FORCEINLINE pack<int64_t,4, avx_>
  toint_( BOOST_SIMD_SUPPORTS(avx2_)
        , pack<double,4,avx_> const& a0
        ) BOOST_NOEXCEPT
  {
    return  _mm256_cvtepi32_epi64( _mm256_cvttpd_epi32(a0));
  }

} } }

#endif
