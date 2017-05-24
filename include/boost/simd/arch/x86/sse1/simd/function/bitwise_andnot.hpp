//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_BITWISE_ANDNOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_BITWISE_ANDNOT_HPP_INCLUDED

#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  pack<float,4,sse_> bitwise_andnot_ ( BOOST_SIMD_SUPPORTS(sse1_)
                                     , pack<float,4,sse_> const& a0
                                     , pack<float,4,sse_> const& a1
                                     ) BOOST_NOEXCEPT
  {
    return _mm_andnot_ps(a1, a0);
  }
} } }

#endif
