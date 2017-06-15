//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_EQUAL_HPP_INCLUDED
#include <type_traits>
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  bs::as_logical_t<pack<double,2,sse_>> is_equal_( BOOST_SIMD_SUPPORTS(sse2_)
                                            , pack<double,2,sse_> const& a0
                                            , pack<double,2,sse_> const& a1
                                            ) BOOST_NOEXCEPT
  {
    return _mm_cmpeq_pd(a0,a1);
  }

  template<typename T>
  BOOST_FORCEINLINE
  bs::as_logical_t<pack<T,16,sse_>> is_equal_ ( BOOST_SIMD_SUPPORTS(sse2_)
                                              , pack<T,16,sse_> const& a0
                                              , pack<T,16,sse_> const& a1
                                              ) BOOST_NOEXCEPT
  {
    return _mm_cmpeq_epi8(a0,a1);
  }

  template<typename T>
  BOOST_FORCEINLINE
  bs::as_logical_t<pack<T,8,sse_>> is_equal_( BOOST_SIMD_SUPPORTS(sse2_)
                                            , pack<T,8,sse_> const& a0
                                            , pack<T,8,sse_> const& a1
                                            ) BOOST_NOEXCEPT
  {
    return _mm_cmpeq_epi16(a0,a1);
  }

  template< typename T
          , typename = typename std::enable_if<std::is_integral<T>::value>::type
          >
  BOOST_FORCEINLINE
  bs::as_logical_t<pack<T,4,sse_>> is_equal_( BOOST_SIMD_SUPPORTS(sse2_)
                                            , pack<T,4,sse_> const& a0
                                            , pack<T,4,sse_> const& a1
                                            ) BOOST_NOEXCEPT
  {
    return _mm_cmpeq_epi32(a0,a1);
  }

} } }

#endif
