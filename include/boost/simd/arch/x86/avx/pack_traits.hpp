//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_PACK_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_PACK_TRAITS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/arch/x86/sse2/pack_traits.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <boost/simd/detail/pack_traits.hpp>
#include <boost/simd/detail/pack_support.hpp>

#if defined __GNUC__ && __GNUC__>=6
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wignored-attributes"
#endif

namespace boost { namespace simd
{
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  ,32, __m256i, ::boost::simd::avx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t ,32, __m256i, ::boost::simd::avx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         ,32, __m256i, ::boost::simd::avx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int16_t ,16, __m256i, ::boost::simd::avx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint16_t,16, __m256i, ::boost::simd::avx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(float        , 8, __m256 , ::boost::simd::avx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int32_t , 8, __m256i, ::boost::simd::avx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint32_t, 8, __m256i, ::boost::simd::avx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(double       , 4, __m256d, ::boost::simd::avx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int64_t , 4, __m256i, ::boost::simd::avx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint64_t, 4, __m256i, ::boost::simd::avx_)
} }

#if defined __GNUC__ && __GNUC__>=6
#pragma GCC diagnostic pop
#endif

#endif
