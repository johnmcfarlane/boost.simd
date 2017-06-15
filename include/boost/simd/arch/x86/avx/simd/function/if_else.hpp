//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_floating.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  template < typename T>
  BOOST_FORCEINLINE
  pack<float,8,avx_>
  if_else_( BOOST_SIMD_SUPPORTS(avx_)
          , pack<logical<T>,8,avx_> const& a0
          , pack<float,8,avx_> const& a1
          , pack<float,8,avx_> const& a2
          ) BOOST_NOEXCEPT
  {
    using p_t = pack<float,8,avx_>;
    return _mm256_blendv_ps(a2, a1, bitwise_cast<p_t>(genmask(a0)));
  }

  template < typename T>
  BOOST_FORCEINLINE
  pack<double,4,avx_>
  if_else_( BOOST_SIMD_SUPPORTS(avx_)
          , pack<logical<T>,4,avx_> const& a0
          , pack<double,4,avx_> const& a1
          , pack<double,4,avx_> const& a2
          ) BOOST_NOEXCEPT
  {
    using p_t = pack<double,4,avx_>;
    return _mm256_blendv_pd(a2, a1, bitwise_cast<p_t>(genmask(a0)));
  }

  template < typename T, typename U, std::size_t N,
  typename =  typename std::enable_if<std::is_integral<U>::value
                                      &&(N <= 8)>
  >
  BOOST_FORCEINLINE
  pack<U,N,sse_>
  if_else_( BOOST_SIMD_SUPPORTS(avx_)
          , pack<logical<T>,N,avx_> const& a0
          , pack<U,N,avx_> const& a1
          , pack<U,N,avx_> const& a2
          ) BOOST_NOEXCEPT
  {
    using p_t = pack<U,N,avx_>;
    using pf_t = f_t<p_t>;
    return bitwise_cast<p_t>(if_else(a0, bitwise_cast<pf_t>(a1), bitwise_cast<pf_t>(a2)));
  }

} } }

#endif
