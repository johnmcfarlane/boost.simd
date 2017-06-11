//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_HMSB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_HMSB_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/bitset.hpp>

namespace boost { namespace simd { namespace detail
{
  namespace bs = boost::simd;

  template < typename T>
  BOOST_FORCEINLINE
  bs::bitset<8> hmsb_( BOOST_SIMD_SUPPORTS(ssse3_)
                          , pack<T,8,sse_> const& a0) BOOST_NOEXCEPT
  {
    using s8type =  pack<std::int8_t,16,sse_>;
    s8type mask = { 0x01,0x03,0x05,0x07,0x09,0x0B,0x0D,0x0F
                    ,-128,-128,-128,-128,-128,-128,-128,-128
    };
    return _mm_movemask_epi8(_mm_shuffle_epi8(bitwise_cast<s8type>(a0), mask));
  }

} } }

#endif
