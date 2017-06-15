//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_CEIL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_CEIL_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  pack<float,4,sse_> ceil_ ( BOOST_SIMD_SUPPORTS(sse4_1_)
                           , pack<float,4,sse_> const& a0
                           ) BOOST_NOEXCEPT
  {
    return _mm_ceil_ps(a0);
  }
  BOOST_FORCEINLINE
  pack<double,2,sse_> ceil_ ( BOOST_SIMD_SUPPORTS(sse4_1_)
                            , pack<double,2,sse_> const& a0
                            ) BOOST_NOEXCEPT
  {
    return _mm_ceil_pd(a0);
  }

} } }

#endif
