//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MAX_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_MAX_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  pack<double,2,sse_>
  max_ ( BOOST_SIMD_SUPPORTS(sse2_)
       , pack<double,2,sse_> const& a0
       , pack<double,2,sse_> const& a1
       ) BOOST_NOEXCEPT
  {
    return _mm_max_pd(a1, a0);
  }

  BOOST_FORCEINLINE
  pack<std::int16_t,8,sse_>
  max_ ( BOOST_SIMD_SUPPORTS(sse2_)
       , pack<std::int16_t,8,sse_> const& a0
       , pack<std::int16_t,8,sse_> const& a1
       ) BOOST_NOEXCEPT
  {
    return _mm_max_epi16(a0, a1);
  }

  BOOST_FORCEINLINE
  pack<std::uint8_t,16,sse_>
  max_ ( BOOST_SIMD_SUPPORTS(sse2_)
       , pack<std::uint8_t,16,sse_> const& a0
       , pack<std::uint8_t,16,sse_> const& a1
       ) BOOST_NOEXCEPT
  {
    return _mm_max_epu8(a0, a1);
  }

} } }

#endif
