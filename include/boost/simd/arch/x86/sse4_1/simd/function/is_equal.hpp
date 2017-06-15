//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED
#include <type_traits>
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  simd::as_logical_t<pack<std::uint64_t,2,sse_>> is_equal_( BOOST_SIMD_SUPPORTS(sse4_1_)
                                                        , pack<std::uint64_t,2,sse_> const& a0
                                                        , pack<std::uint64_t,2,sse_> const& a1
                                                        ) BOOST_NOEXCEPT
  {
    return _mm_cmpeq_epi64(a0,a1);
  }

  BOOST_FORCEINLINE
  simd::as_logical_t<pack<std::int64_t,2,sse_>> is_equal_( BOOST_SIMD_SUPPORTS(sse4_1_)
                                                       , pack<std::int64_t,2,sse_> const& a0
                                                       , pack<std::int64_t,2,sse_> const& a1
                                                       ) BOOST_NOEXCEPT
  {
    return _mm_cmpeq_epi64(a0,a1);
  }

} } }

#endif
