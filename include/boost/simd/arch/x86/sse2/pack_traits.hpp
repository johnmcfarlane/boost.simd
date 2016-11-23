//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_PACK_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_PACK_TRAITS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/arch/x86/sse1/pack_traits.hpp>
#include <boost/simd/detail/pack_traits.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <boost/simd/detail/pack_support.hpp>

#if defined __GNUC__ && __GNUC__>=6
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wignored-attributes"
#endif

namespace boost { namespace simd
{
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  ,16, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t ,16, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         ,16, __m128i, ::boost::simd::sse_)

  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int16_t , 8, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint16_t, 8, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  , 8, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t , 8, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         , 8, __m128i, ::boost::simd::sse_)

  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int32_t , 4, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint32_t, 4, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int16_t , 4, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint16_t, 4, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  , 4, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t , 4, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         , 4, __m128i, ::boost::simd::sse_)

  BOOST_SIMD_ENABLE_PACK_SUPPORT(double       , 2, __m128d, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int64_t , 2, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint64_t, 2, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int32_t , 2, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint32_t, 2, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int16_t , 2, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint16_t, 2, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  , 2, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t , 2, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         , 2, __m128i, ::boost::simd::sse_)

  BOOST_SIMD_ENABLE_PACK_SUPPORT(double       , 1, __m128d, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int64_t , 1, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint64_t, 1, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int32_t , 1, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint32_t, 1, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int16_t , 1, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint16_t, 1, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  , 1, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t , 1, __m128i, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         , 1, __m128i, ::boost::simd::sse_)
} }

#if defined __GNUC__ && __GNUC__>=6
#pragma GCC diagnostic pop
#endif

#endif
