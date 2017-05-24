//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_MINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_MINUS_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<float,4> minus_( BOOST_SIMD_SUPPORTS(sse1_)
                                        , pack<float,4> const& a0, pack<float,4> const& a1
                                        ) BOOST_NOEXCEPT
  {
    return _mm_sub_ps(a0,a1);
  }
} } }

#endif
