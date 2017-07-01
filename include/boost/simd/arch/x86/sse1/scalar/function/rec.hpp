//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SCALAR_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SCALAR_FUNCTION_REC_HPP_INCLUDED

#include <boost/simd/function/raw.hpp>

namespace boost { namespace simd { namespace detail
{
   template<std::size_t N>
  BOOST_FORCEINLINE  float
  rec_(BOOST_SIMD_SUPPORTS(sse1_)
             , raw_tag const&
             , float a0) BOOST_NOEXCEPT
  {
    float inv;
    _mm_store_ss( &inv, _mm_rcp_ss( _mm_load_ss( &a0 ) ) );
    return inv;
  }

} } }

#endif
