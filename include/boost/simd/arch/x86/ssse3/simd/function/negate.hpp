
//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_NEGATE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_NEGATE_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  pack<std::int8_t,16,sse_>
  negate_( BOOST_SIMD_SUPPORTS(ssse3_)
         , pack<std::int8_t,16,sse_> const& a0
         , pack<std::int8_t,16,sse_> const& a1
          ) BOOST_NOEXCEPT
  {
    return _mm_sign_epi8(a0, a1);
  }

  BOOST_FORCEINLINE
  pack<std::int16_t,8,sse_>
  negate_( BOOST_SIMD_SUPPORTS(ssse3_)
         , pack<std::int16_t,8,sse_> const& a0
         , pack<std::int16_t,8,sse_> const& a1
          ) BOOST_NOEXCEPT
  {
    return _mm_sign_epi16(a0, a1);
  }

  BOOST_FORCEINLINE
  pack<std::int32_t,4,sse_>
  negate_( BOOST_SIMD_SUPPORTS(ssse3_)
         , pack<std::int32_t,4,sse_> const& a0
         , pack<std::int32_t,4,sse_> const& a1
         ) BOOST_NOEXCEPT
  {
    return _mm_sign_epi32(a0, a1);
  }
} } }

#endif
