//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_MIN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_MIN_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>


namespace boost { namespace simd { namespace detail
{

  BOOST_FORCEINLINE
  pack<std::int8_t,16,sse_>
  min_ ( BOOST_SIMD_SUPPORTS(sse4_1_)
       , pack<std::int8_t,16,sse_> const& a0
       , pack<std::int8_t,16,sse_> const& a1
       ) BOOST_NOEXCEPT
  {
    return _mm_min_epi8(a0, a1);
  }

  BOOST_FORCEINLINE
  pack<std::uint16_t,8,sse_>
  min_ ( BOOST_SIMD_SUPPORTS(sse4_1_)
       , pack<std::uint16_t,8,sse_> const& a0
       , pack<std::uint16_t,8,sse_> const& a1
       ) BOOST_NOEXCEPT
  {
    return _mm_min_epu16(a0, a1);
  }

  BOOST_FORCEINLINE
  pack<std::uint32_t,4,sse_>
  min_ ( BOOST_SIMD_SUPPORTS(sse4_1_)
       , pack<std::uint32_t,4,sse_> const& a0
       , pack<std::uint32_t,4,sse_> const& a1
       ) BOOST_NOEXCEPT
  {
    return _mm_min_epu32(a0, a1);
  }

  BOOST_FORCEINLINE
  pack<std::int32_t,4,sse_>
  min_ ( BOOST_SIMD_SUPPORTS(sse4_1_)
       , pack<std::int32_t,4,sse_> const& a0
       , pack<std::int32_t,4,sse_> const& a1
       ) BOOST_NOEXCEPT
  {
    return _mm_min_epi32(a0, a1);
  }

} } }

#endif
