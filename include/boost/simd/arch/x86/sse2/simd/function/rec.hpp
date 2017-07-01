//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_REC_HPP_INCLUDED
#include <boost/simd/function/raw.hpp>

namespace boost { namespace simd { namespace detail
{
   template<std::size_t N>
  BOOST_FORCEINLINE  pack<double,2,sse_>
  rec_(BOOST_SIMD_SUPPORTS(sse2_)
             , raw_tag const&
             , pack<double,2,sse_> a0) BOOST_NOEXCEPT
  {
    return _mm_cvtps_pd(_mm_rcp_ps(_mm_cvtpd_ps(a0))); //The maximum error for this approximation is 1.5e-12
  }

} } }

#endif
