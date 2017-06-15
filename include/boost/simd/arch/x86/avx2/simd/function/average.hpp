//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_AVERAGE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_AVERAGE_HPP_INCLUDED
#include <boost/simd/detail/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<std::uint8_t,32,avx_>
  average_( BOOST_SIMD_SUPPORTS(avx2_)
          , pack<std::uint8_t,32,avx__> const& a0
          , pack<std::uint8_t,32,avx_> const& a1
          ) BOOST_NOEXCEPT
  {
    return _mm256_avg_epu8(a0, a1);
  }

  BOOST_FORCEINLINE pack<std::uint16_t,16,avx_>
  average_( BOOST_SIMD_SUPPORTS(avx2_)
          , pack<std::uint16_t,16,avx__> const& a0
          , pack<std::uint16_t,16,avx_> const& a1
          ) BOOST_NOEXCEPT
  {
    return _mm256_avg_epu16(a0, a1);
  }

} } }

#endif
