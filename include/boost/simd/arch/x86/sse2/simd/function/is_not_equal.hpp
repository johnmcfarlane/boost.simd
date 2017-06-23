//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_NOT_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_NOT_EQUAL_HPP_INCLUDED
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>


namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  as_logical_t<pack<double,2,sse_>>
  is_not_equal_( BOOST_SIMD_SUPPORTS(sse2_)
           , pack<double,2,sse_> const& a0
           , pack<double,2,sse_> const& a1
           ) BOOST_NOEXCEPT
  {
    return _mm_cmpneq_pd(a0,a1);
  }

} } }

#endif
