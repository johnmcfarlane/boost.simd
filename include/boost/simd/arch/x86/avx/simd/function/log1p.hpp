//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_LOG1P_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_LOG1P_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  // plain algorithm not using integers is better in avx
  BOOST_FORCEINLINE
  pack<double,4,avx_> log1p_ ( BOOST_SIMD_SUPPORTS(avx_)
                            , pack<double,4,avx_> const& a0
                            ) BOOST_NOEXCEPT
  {
    return plain_(log1p)(a0);
  }

} } }

#endif
