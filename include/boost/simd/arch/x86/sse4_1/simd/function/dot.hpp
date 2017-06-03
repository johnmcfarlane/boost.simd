//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_DOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_DOT_HPP_INCLUDED
#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  double dot_ (BOOST_SIMD_SUPPORTS(sse4_1_)
            , pack<double, 2, sse_> const& a0
            , pack<double, 2, sse_> const& a1
            ) BOOST_NOEXCEPT
  {
    pack<double, 2, sse_> r = _mm_dp_pd(a0, a1, 0xFF);
    return r[0];
  }

  BOOST_FORCEINLINE
  float dot_ (BOOST_SIMD_SUPPORTS(sse4_1_)
            , pack<float, 4, sse_> const& a0
            , pack<float, 4, sse_> const& a1
            ) BOOST_NOEXCEPT
  {
    pack<float, 4, sse_> r = _mm_dp_ps(a0, a1, 0xFF);
    return r[0];
  }

} } }

#endif
