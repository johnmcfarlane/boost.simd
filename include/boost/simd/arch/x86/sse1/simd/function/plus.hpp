//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_PLUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_PLUS_HPP_INCLUDED

#include <boost/simd/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<float,4> plus_ ( BOOST_SIMD_SUPPORTS(sse1_)
                                        , pack<float,4> const& a0, pack<float,4> const& a1
                                        ) BOOST_NOEXCEPT
  {
    return _mm_add_ps(a0,a1);
  }
} } }

#endif

