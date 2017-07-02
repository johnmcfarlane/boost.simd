//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_HMSB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_HMSB_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/slice.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/bitset.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  namespace bs = boost::simd;

  template < typename T>
  BOOST_FORCEINLINE
  bs::bitset<32> hmsb_ ( BOOST_SIMD_SUPPORTS(avx_)
                      , pack<T,32,avx_> const& a0
                      ) BOOST_NOEXCEPT
  {
    auto h = _mm_movemask_epi8(slice_high(a0));
    auto l = _mm_movemask_epi8(slice_low (a0));
    return l | (h << 16);
  }

  template < typename T>
  BOOST_FORCEINLINE
  bs::bitset<16> hmsb_ ( BOOST_SIMD_SUPPORTS(avx_)
                      , pack<T,16,avx_> const& a0
                      ) BOOST_NOEXCEPT
  {
    using s8type = typename pack<T,16,avx_>::template retype<int8_t, 16>;
    s8type mask = {1,3,5,7,9,11,13,15,-128,-128,-128,-128,-128,-128,-128,-128};

    auto l = _mm_movemask_epi8(_mm_shuffle_epi8(bitwise_cast<s8type>(slice_low(a0)), mask));
    auto h = _mm_movemask_epi8(_mm_shuffle_epi8(bitwise_cast<s8type>(slice_high(a0)), mask));

    return l | (h << 8);
  }

  BOOST_FORCEINLINE
  bs::bitset<4> hmsb_ ( BOOST_SIMD_SUPPORTS(avx_)
                      , pack<double,4,avx_> const& a0
                      ) BOOST_NOEXCEPT
  {
    return _mm256_movemask_pd(a0);
  }

  BOOST_FORCEINLINE
  bs::bitset<8> hmsb_ ( BOOST_SIMD_SUPPORTS(avx_)
                      , pack<T,8,avx_> const& a0
                      ) BOOST_NOEXCEPT
  {
   using p_t = pack<T,8,avx_>;
    return hmsb(bitwise_cast<as_f_t<p_t>>(a0));
  }

} } }

#endif
