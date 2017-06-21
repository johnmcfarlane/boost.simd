//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_TOINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_TOINT_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/split_low.hpp>
#include <boost/simd/constant/zero.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<int64_t,2, sse_>
  toint_( BOOST_SIMD_SUPPORTS(sse2_)
        , pack<double,2,sse_> const& a0
        ) BOOST_NOEXCEPT
  {
    pack<int32_t,4, sse_>out = _mm_cvttpd_epi32(a0);
    return bs::split_low(out);
  }

  BOOST_FORCEINLINE pack<int32_t,4, sse_>
  toint_( BOOST_SIMD_SUPPORTS(sse2_)
        , pedantic_tag const &
        , pack<float,4,sse_> const& a0
        ) BOOST_NOEXCEPT
  {
    return _mm_cvttps_epi32(a0);
  }

} } }

#endif
