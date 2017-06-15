//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_INTERLEAVE_ODD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_INTERLEAVE_ODD_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  pack<double,2,sse_> interleave_odd_ ( BOOST_SIMD_SUPPORTS(sse2_)
                      , pack<double,2,sse_> const& a0
                      , pack<double,2,sse_> const& a1
                      ) BOOST_NOEXCEPT
  {
    return _mm_unpackhi_pd(a0,a1);
  }

  template < typename T>
  typename std::enable_if<std::is_integral<T>::value,
                          pack<T,4,sse_>>::type
  interleave_odd_ ( BOOST_SIMD_SUPPORTS(sse2_)
                  , pack<T,4,sse_> const& a0
                  , pack<T,4,sse_> const& a1
                  ) BOOST_NOEXCEPT
  {
    return _mm_unpackhi_epi32 ( _mm_castps_si128(_mm_shuffle_ps ( _mm_castsi128_ps(a0)
                                                                , _mm_castsi128_ps(a0)
                                                                , _MM_SHUFFLE(3,1,3,1)
                                                                )
                                                )
                              , _mm_castps_si128(_mm_shuffle_ps ( _mm_castsi128_ps(a1)
                                                                , _mm_castsi128_ps(a1)
                                                                , _MM_SHUFFLE(3,1,3,1)
                                                                )
                                                )
                              );
  }

  template < typename T>
  typename std::enable_if<std::is_integral<T>::value,
                          pack<T,2,sse_>>::type
  interleave_odd_ ( BOOST_SIMD_SUPPORTS(sse2_)
                  , pack<T,2,sse_> const& a0
                  , pack<T,2,sse_> const& a1
                  ) BOOST_NOEXCEPT
  {
    return _mm_unpackhi_epi64(a0,a1);
  }

} } }

#endif
