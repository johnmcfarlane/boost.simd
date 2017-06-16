//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_DEINTERLEAVE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_DEINTERLEAVE_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/deinterleave_first.hpp>
#include <boost/simd/function/deinterleave_second.hpp>
#include <boost/simd/function/combine.hpp>
#include <boost/simd/function/slice.hpp>
#include <array>

namespace boost { namespace simd { namespace detail
{
  template< typename T, std::size_t N >
  BOOST_FORCEINLINE pack<T,N,avx_> deinterleave_( BOOST_SIMD_SUPPORTS(avx_)
                                                , pack<T,N,avx_> const& a0
                                                , pack<T,N,avx_> const& a1
                                                ) BOOST_NOEXCEPT
  {
    auto s00 = slice_low(a0);
    auto s01 = slice_high(a0);
    auto s10 = slice_low(a1);
    auto s11 = slice_high(a1);

    auto f = combine(deinterleave_first (s00,s01), deinterleave_first (s10,s11));
    auto s = combine(deinterleave_second(s00,s01), deinterleave_second(s10,s11));

    std::array<pack<T,N,avx_>,2> that{f,s};
    return that;
  }

} } }

#endif
