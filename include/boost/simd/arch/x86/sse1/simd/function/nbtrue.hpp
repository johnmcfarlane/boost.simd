//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_NBTRUE_HPP_INCLUDED
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/popcnt.hpp>
#include <boost/simd/function/genmask.hpp>


namespace boost { namespace simd { namespace detail
{
  template < typename T>
  BOOST_FORCEINLINE
  std::size_t nbtrue_ ( BOOST_SIMD_SUPPORTS(sse2_)
                      , pack<float,4,sse_> const& a0
                      ) BOOST_NOEXCEPT
  {
    return  simd::popcnt(_mm_movemask_ps(genmask(a0)));
  }

} } }

#endif

