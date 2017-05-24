//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_BITWISE_ANDNOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_BITWISE_ANDNOT_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<double,2,sse_> bitwise_andnot_( BOOST_SIMD_SUPPORTS(sse2_)
                                                    , pack<double,2,sse_> const& a0
                                                    , pack<double,2,sse_> const& a1
                                                    ) BOOST_NOEXCEPT
  {
    return _mm_andnot_pd(a1, a0);
  }

  template<typename T, std::size_t N
          , typename = typename std::enable_if<std::is_integral<T>::value>::type
          >
  BOOST_FORCEINLINE pack<T, N, sse_> bitwise_andnot_ ( BOOST_SIMD_SUPPORTS(sse2_)
                                                  , pack<T,N,sse_> const& a0
                                                  , pack<T,N,sse_> const& a1
                                                  ) BOOST_NOEXCEPT
  {
    return _mm_andnot_si128(a1,a0);
  }
} } }

#endif
