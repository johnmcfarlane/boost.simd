//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_EXTRACT_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_EXTRACT_INCLUDED

#include <boost/simd/arch/common/generic/function/autodispatcher.hpp>
#include <boost/simd/function/scalar/extract.hpp>
#include <boost/simd/arch/common/simd/function/extract.hpp>

#if defined(BOOST_HW_SIMD_X86)

#if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE2_VERSION
#include <boost/simd/arch/x86/sse2/simd/function/extract.hpp>
#endif

#if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE4_1_VERSION
#include <boost/simd/arch/x86/sse4_1/simd/function/extract.hpp>
#endif

#if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX_VERSION
//#include <boost/simd/arch/x86/avx/simd/function/extract.hpp>
#endif

#if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX2_VERSION
//#include <boost/simd/arch/x86/avx2/simd/function/extract.hpp>
#endif

#endif
#endif

