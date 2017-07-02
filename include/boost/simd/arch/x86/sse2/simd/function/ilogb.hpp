//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_ILOGB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_ILOGB_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/if_inc.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/constant.hpp>
#include <boost/simd/detail/dispatch/meta/upgrade.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<uint8_t,16,sse_>
  ilogb_( BOOST_SIMD_SUPPORTS(sse2_)
        , pack<uint8_t,16,sse_> const& a0
        ) BOOST_NOEXCEPT
  {
      using p_t =  pack<uint8_t,16,sse_>;
      using ui16_t =  bd::upgrade_t<p_t>;
      const p_t mask =  Constant<p_t, 0x7f>();
      p_t n = a0;
      p_t i = One<p_t>();
      n = bitwise_and(mask, shift_right(bitwise_cast<ui16_t>(n), 1));
      i = if_inc(is_nez(n), i);
      n = bitwise_and(mask, shift_right(bitwise_cast<ui16_t>(n), 1));
      i = if_inc(is_nez(n), i);
      n = bitwise_and(mask, shift_right(bitwise_cast<ui16_t>(n), 1));
      i = if_inc(is_nez(n), i);
      n = bitwise_and(mask, shift_right(bitwise_cast<ui16_t>(n), 1));
      i = if_inc(is_nez(n), i);
      n = bitwise_and(mask, shift_right(bitwise_cast<ui16_t>(n), 1));
      i = if_inc(is_nez(n), i);
      n = bitwise_and(mask, shift_right(bitwise_cast<ui16_t>(n), 1));
      i = if_inc(is_nez(n), i);
      n = bitwise_and(mask, shift_right(bitwise_cast<ui16_t>(n), 1));
      i = if_inc(is_nez(n), i);
      return dec(i);
  }

  BOOST_FORCEINLINE pack<int8_t,16,sse_>
  ilogb_( BOOST_SIMD_SUPPORTS(sse2_)
        , pack<int8_t,16,sse_> const& a0
        ) BOOST_NOEXCEPT
  {
      using p_t =  pack<int8_t,16,sse_>;
      return bitwise_cast<p_t>(ilogb(bitwise_cast<as_ui_t<p_t>>(saturated_(abs)(a0))));
  }

} } }

#endif
