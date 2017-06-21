//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_LOG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_LOG_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  // plain algorithm not using integers is better in avx
  BOOST_FORCEINLINE
  pack<double,4,avx_> log2_ ( BOOST_SIMD_SUPPORTS(avx_)
                            , pack<double,4,avx_> const& a0
                            ) BOOST_NOEXCEPT
  {
    return plain_(log2)(a0);
  }

} } }

#endif
