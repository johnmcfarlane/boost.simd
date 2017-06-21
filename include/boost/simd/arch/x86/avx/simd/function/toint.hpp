//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_TOINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_TOINT_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<int32_t,8, avx_>
  toint_( BOOST_SIMD_SUPPORTS(avx_)
        , pedantic_tag const &
        , pack<float,8,avx_> const& a0
        ) BOOST_NOEXCEPT
  {
    return _m256_cvttps_epi32(a0);
  }

  BOOST_FORCEINLINE pack<int32_t,8, avx_>
  toint_( BOOST_SIMD_SUPPORTS(avx_)
        , pack<float,8,avx_> const& a0
        ) BOOST_NOEXCEPT
  {
    return _m256_cvttps_epi32(a0);
  }

} } }

#endif
