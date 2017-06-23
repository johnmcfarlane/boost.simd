//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_NOT_GREATER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_NOT_GREATER_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  as_logical_t<pack<double,2,sse_>>
  is_not_greater_ ( BOOST_SIMD_SUPPORTS(sse1_)
                  , pack<double,2,sse_> const& a0
                  , pack<double,2,sse_> const& a1
                  ) BOOST_NOEXCEPT
  {
    return _mm_cmpngt_pd(a0,a1);
  }

} } }

#endif
