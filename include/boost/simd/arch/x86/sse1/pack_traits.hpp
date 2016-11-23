//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_PACK_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_PACK_TRAITS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <boost/simd/detail/pack_traits.hpp>
#include <boost/simd/arch/common/simd/abi_of.hpp>
#include <boost/simd/detail/pack_support.hpp>

#if defined __GNUC__ && __GNUC__>=6
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wignored-attributes"
#endif

namespace boost { namespace simd
{
  BOOST_SIMD_ENABLE_PACK_SUPPORT(float, 4, __m128, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(float, 2, __m128, ::boost::simd::sse_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(float, 1, __m128, ::boost::simd::sse_)
} }

#if defined __GNUC__ && __GNUC__>=6
#pragma GCC diagnostic pop
#endif

#endif
