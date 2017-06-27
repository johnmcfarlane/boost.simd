//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/popcnt.hpp>

namespace boost { namespace simd { namespace detail
{

  template < typename T>
  BOOST_FORCEINLINE
  std::size_t nbtrue_ ( BOOST_SIMD_SUPPORTS(sse2_)
                      , pack<double,2,sse_> const& a0
                      ) BOOST_NOEXCEPT
  {
    return  simd::popcnt(_mm_movemask_pd(genmask(a0)));
  }


  template < typename T, std::size_t N >
  BOOST_FORCEINLINE  std::size_t
  nbtrue_ ( BOOST_SIMD_SUPPORTS(sse2_)
                      , pack<T,N,sse_> const& a0
                      ) BOOST_NOEXCEPT
  {
      using i8_t= pack<int8_t,16>;
      i8_t tmp = bitwise_cast<i8_t>(genmask(a0));
      return bs::popcnt(_mm_movemask_epi8(tmp))*N >> 4;
  }

} } }

#endif

