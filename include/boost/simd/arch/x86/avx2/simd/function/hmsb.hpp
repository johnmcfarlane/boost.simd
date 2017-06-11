//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_HMSB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_HMSB_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/bitset.hpp>

namespace boost { namespace simd { namespace ext
{
  template < typename T >
  BOOST_FORCEINLINE
  bs::bitset<32> hmsb_( BOOST_SIMD_SUPPORTS(avx2_)
                      , pack<T,32,avx_> const& a0
                      ) BOOST_NOEXCEPT
  {
    return _mm256_movemask_epi8(a0);
  }
} } }

#endif
