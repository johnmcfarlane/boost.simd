//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_XOP_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_XOP_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED
#include <type_traits>
#include <boost/simd/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>

#if !defined(_MM_PCOMCTRL_EQ)
#define _MM_PCOMCTRL_EQ 4
#define BOOST_SIMD_MISSING_MM_PCOMCTRL_EQ
#endif

#if BOOST_HW_SIMD_X86_AMD_XOP
namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  bs::as_logical_t<pack<std::int8_t,16,sse_>> is_equal_( BOOST_SIMD_SUPPORTS(avx_)
                                                       , pack<std::int8_t,16,sse_> const& a0
                                                       , pack<std::int8_t,16,sse_> const& a1
                                                       ) BOOST_NOEXCEPT
  {
#if defined(__clang__)
    return _mm_com_epi8(a0,a1,_MM_PCOMCTRL_EQ);
#else
    return _mm_comeq_epi8(a0,a1);
#endif
  }

  BOOST_FORCEINLINE
  bs::as_logical_t<pack<std::int16_t,8,sse_>> is_equal_( BOOST_SIMD_SUPPORTS(avx_)
                                                       , pack<std::int16_t,8,sse_> const& a0
                                                       , pack<std::int16_t,8,sse_> const& a1
                                                       ) BOOST_NOEXCEPT
  {
#if defined(__clang__)
    return _mm_com_epi16(a0,a1,_MM_PCOMCTRL_EQ);
#else
    return _mm_comeq_epi16(a0,a1);
#endif
  }

  BOOST_FORCEINLINE
  bs::as_logical_t<pack<std::int32_t,4,sse_>> is_equal_( BOOST_SIMD_SUPPORTS(avx_)
                                                       , pack<std::int32_t,4,sse_> const& a0
                                                       , pack<std::int32_t,4,sse_> const& a1
                                                       ) BOOST_NOEXCEPT
  {
#if defined(__clang__)
    return _mm_com_epi32(a0,a1,_MM_PCOMCTRL_EQ);
#else
    return _mm_comeq_epi32(a0,a1);
#endif
  }


  BOOST_FORCEINLINE
  bs::as_logical_t<pack<std::int64_t,2,sse_>> is_equal_( BOOST_SIMD_SUPPORTS(avx_)
                                                       , pack<std::int64_t,2,sse_> const& a0
                                                       , pack<std::int64_t,2,sse_> const& a1
                                                       ) BOOST_NOEXCEPT
  {
#if defined(__clang__)
    return _mm_com_epi64(a0,a1,_MM_PCOMCTRL_EQ);
#else
    return _mm_comeq_epi64(a0,a1);
#endif
  }

  //unsigned types

  BOOST_FORCEINLINE
  bs::as_logical_t<pack<std::uint8_t,16,sse_>> is_equal_( BOOST_SIMD_SUPPORTS(avx_)
                                                        , pack<std::uint8_t,16,sse_> const& a0
                                                        , pack<std::uint8_t,16,sse_> const& a1
                                                        ) BOOST_NOEXCEPT
  {
#if defined(__clang__)
    return _mm_com_epu8(a0,a1,_MM_PCOMCTRL_EQ);
#else
    return _mm_comeq_epu8(a0,a1);
#endif
  }

  BOOST_FORCEINLINE
  bs::as_logical_t<pack<std::uint16_t,8,sse_>> is_equal_( BOOST_SIMD_SUPPORTS(avx_)
                                                        , pack<std::uint16_t,8,sse_> const& a0
                                                        , pack<std::uint16_t,8,sse_> const& a1
                                                        ) BOOST_NOEXCEPT
  {
#if defined(__clang__)
    return _mm_com_epu16(a0,a1,_MM_PCOMCTRL_EQ);
#else
    return _mm_comeq_epu16(a0,a1);
#endif
  }

  BOOST_FORCEINLINE
  bs::as_logical_t<pack<std::uint32_t,4,sse_>> is_equal_( BOOST_SIMD_SUPPORTS(avx_)
                                                        , pack<std::uint32_t,4,sse_> const& a0
                                                        , pack<std::uint32_t,4,sse_> const& a1
                                                        ) BOOST_NOEXCEPT
  {
#if defined(__clang__)
    return _mm_com_epu32(a0,a1,_MM_PCOMCTRL_EQ);
#else
    return _mm_comeq_epu32(a0,a1);
#endif
  }


  BOOST_FORCEINLINE
  bs::as_logical_t<pack<std::uint64_t,2,sse_>> is_equal_( BOOST_SIMD_SUPPORTS(avx_)
                                                        , pack<std::uint64_t,2,sse_> const& a0
                                                        , pack<std::uint64_t,2,sse_> const& a1
                                                        ) BOOST_NOEXCEPT
  {
#if defined(__clang__)
    return _mm_com_epu64(a0,a1,_MM_PCOMCTRL_EQ);
#else
    return _mm_comeq_epu64(a0,a1);
#endif
  }

} } }
#endif

#if defined(BOOST_SIMD_MISSING_MM_PCOMCTRL_EQ)
#undef _MM_PCOMCTRL_EQ
#undef BOOST_SIMD_MISSING_MM_PCOMCTRL_EQ
#endif

#endif
