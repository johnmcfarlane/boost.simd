//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_INEARBYINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_INEARBYINT_HPP_INCLUDED
#include <boost/simd/detail/pack.hpp>


namespace boost { namespace simd { namespace detail
{
  template<std::size_t N>
  BOOST_FORCEINLINE  pack<std::int32_t,4,sse_>
  inearbyint_(BOOST_SIMD_SUPPORTS(sse2_)
             , pack<float,4,sse_> a0) BOOST_NOEXCEPT
  {
     return _mm_cvtps_epi32(a0);
  }

} } }

#endif
