//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_2_SIMD_FUNCTION_IS_GREATER_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_2_SIMD_FUNCTION_IS_GREATER_EQUAL_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/logical_not.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  as_logical_t<pack<std::int64_t,2,sse_>>
  is_greater_equal_ ( BOOST_SIMD_SUPPORTS(sse4_2_)
                    , pack<std::int64_t,2,sse_> const& a0
                    , pack<std::int64_t,2,sse_> const& a1
                    ) BOOST_NOEXCEPT
  {
    as_logical_t<pack<std::int64_t,2,sse_>> that = _mm_cmpgt_epi64(a1,a0);
    return logical_not(that);
  }

} } }

#endif
