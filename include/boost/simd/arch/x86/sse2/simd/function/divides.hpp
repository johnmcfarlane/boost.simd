//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_DIVIDES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_DIVIDES_HPP_INCLUDED
#include <boost/simd/detail/pack.hpp>
#include <type_traits>

#if defined(BOOST_SIMD_COMPILER_GCC) && BOOST_SIMD_GCC_VERSION < 40603
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/is_eqz_else.hpp>
#include <boost/simd/function/logical_and.hpp>
#endif


namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<double,2,sse_> divides( BOOST_SIMD_SUPPORTS(sse2_)
                                                    , pack<double,2,sse_> const& a0
                                                    , pack<double,2,sse_> const& a1
                                                    ) BOOST_NOEXCEPT
  {
#if defined(BOOST_SIMD_COMPILER_GCC) && BOOST_SIMD_GCC_VERSION < 40603
      // workaround for GCC bug #50396 fixed in 4.6.3
      return if_nan_else(logical_and(is_eqz(a0), is_eqz(a1)),  _mm_div_pd(a0,a1));
#else
      return  _mm_div_pd(a0,a1);
#endif
  }

} } }

#endif
