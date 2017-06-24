//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_IS_NOT_LESS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_IS_NOT_LESS_EQUAL_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  as_logical_t<pack<float,4,sse_>>
  is_not_less_equal__ ( BOOST_SIMD_SUPPORTS(sse1_)
              , pack<float,4,sse_> const& a0
              , pack<float,4,sse_> const& a1
              ) BOOST_NOEXCEPT
  {
    return _mm_cmpnle_ps(a0,a1);
  }

} } }

#endif
