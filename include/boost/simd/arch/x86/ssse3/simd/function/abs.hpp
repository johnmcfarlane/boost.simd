
//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_ABS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_ABS_HPP_INCLUDED

#include <type_traits>
#include <boost/simd/pack.hpp>
#include <cstdint>

namespace boost { namespace simd { namespace detail
{

  BOOST_FORCEINLINE pack<std::int32_t,4,sse_> abs_ ( BOOST_SIMD_SUPPORTS(ssse3_)
                                          , pack<std::int32_t,4,sse_> const& a0
                                          ) BOOST_NOEXCEPT
  {
    return _mm_abs_epi32(a0);
  }

  BOOST_FORCEINLINE pack<std::int16_t,8,sse_> abs_ ( BOOST_SIMD_SUPPORTS(ssse3_)
                                          , pack<std::int16_t,8,sse_> const& a0
                                          ) BOOST_NOEXCEPT
  {
    return _mm_abs_epi16(a0);
  }

  BOOST_FORCEINLINE pack<std::int8_t,16,sse_> abs_ ( BOOST_SIMD_SUPPORTS(ssse3_)
                                                , pack<std::int8_t,16,sse_> const& a0
                                          ) BOOST_NOEXCEPT
  {
    return _mm_abs_epi8(a0);
  }

} } }

#endif
