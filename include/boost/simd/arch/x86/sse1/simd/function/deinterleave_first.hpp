//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_DEINTERLEAVE_FIRST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_DEINTERLEAVE_FIRST_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{
BOOST_FORCEINLINE
 pack<float,4,sse_> deinterleave_first_ ( BOOST_SIMD_SUPPORTS(sse2_)
                                         , pack<float,4,sse_> const& a0
                                         , pack<float,4,sse_> const& a1
                                         ) BOOST_NOEXCEPT
 {
   return _mm_shuffle_ps(a0, a1, _MM_SHUFFLE(2,0,2,0));
 }

} } }

#endif

