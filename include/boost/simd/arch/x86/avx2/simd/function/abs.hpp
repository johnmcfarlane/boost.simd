//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_ABS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_ABS_HPP_INCLUDED

#include <type_traits>
#include <boost/simd/pack.hpp>

namespace boost { namespace simd { namespace detail
{

  BOOST_FORCEINLINE pack<std::int32_t,8,avx_> abs_ ( BOOST_SIMD_SUPPORTS(avx2_)
                                                   , pack<std::int32_t,8,avx_> const& a0
                                                   ) BOOST_NOEXCEPT
  {
    return _mm256_abs_epi32(a0);
  }

  BOOST_FORCEINLINE pack<std::int16_t,16,avx_> abs_ ( BOOST_SIMD_SUPPORTS(avx2_)
                                                    , pack<std::int16_t,16,avx_> const& a0
                                                    ) BOOST_NOEXCEPT
  {
    return _mm256_abs_epi16(a0);
  }

  BOOST_FORCEINLINE pack<std::int8_t,32,avx_> abs_ ( BOOST_SIMD_SUPPORTS(avx2_)
                                                   , pack<std::int8_t,32,avx_> const& a0
                                                   ) BOOST_NOEXCEPT
  {
    return _mm256_abs_epi8(a0);
  }

} } }

#endif
