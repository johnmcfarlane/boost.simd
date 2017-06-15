//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/genmask.hpp>

namespace boost { namespace simd { namespace detail
{
  template < typename T>
  BOOST_FORCEINLINE
  pack<float,4,sse_>
  if_else_( BOOST_SIMD_SUPPORTS(sse4_1_)
          , pack<logical<T>, 4, sse_> const& a0
          , pack<float,4,sse_> const& a1
          , pack<float,4,sse_> const& a2
          ) BOOST_NOEXCEPT
  {
    using p_t = pack<float,4,sse_>;
    return _mm_blendv_ps(a2, a1, bitwise_cast<p_t>(genmask(a0)));
  }

  template < typename T>
  BOOST_FORCEINLINE
  pack<double,2,sse_>
  if_else_( BOOST_SIMD_SUPPORTS(sse4_1_)
          , pack<logical<T>,2,sse_> const& a0
          , pack<double,2,sse_> const& a1
          , pack<double,2,sse_> const& a2
          ) BOOST_NOEXCEPT
  {
    using p_t = pack<double,2,sse_>;
    return _mm_blendv_pd(a2, a1, bitwise_cast<p_t>(genmask(a0)));
  }

  template < typename T, typename U, std::size_t N,
             typename =  typename std::enable_if<std::is_integral<U>::value >
  >
  BOOST_FORCEINLINE
  pack<U,N,sse_>
  if_else_( BOOST_SIMD_SUPPORTS(sse4_1_)
          , pack<logical<T>,N,sse_> const& a0
          , pack<U,N,sse_> const& a1
          , pack<U,N,sse_> const& a2
          ) BOOST_NOEXCEPT
  {
    using p_t = pack<U,N,sse_>;
   return _mm_blendv_epi8(a2, a1, bitwise_cast<p_t>(genmask(a0)));
  }

} } }

#endif
