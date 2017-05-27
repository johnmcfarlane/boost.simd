//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_SPLAT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/as.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename V>
  BOOST_FORCEINLINE pack<float,4>
  splat_(BOOST_SIMD_SUPPORTS(sse1_), as_<pack<float,4>> const&, V const& v) BOOST_NOEXCEPT
  {
    return _mm_set1_ps( static_cast<float>(v) );
  }
} } }

#endif
