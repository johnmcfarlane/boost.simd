//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_INTERLEAVE_SECOND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_INTERLEAVE_SECOND_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/detail/meta/size_picker.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  pack<double,2,sse_> interleave_second_ ( BOOST_SIMD_SUPPORTS(sse2_)
                                        , pack<double,2,sse_> const& a0
                                        , pack<double,2,sse_> const& a1
                                        ) BOOST_NOEXCEPT
  {
    return _mm_unpackhi_pd(a0,a1);
  }

  template < class T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,sse_> interleave_second_ ( pack<T,N,sse_> const& a0
                                   , pack<T,N,sse_> const& a1
                                    , case_<0> const &
                                    ) BOOST_NOEXCEPT
  {
    return _mm_unpackhi_epi64(a0,a1);
  }

  template < class T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,sse_> interleave_second_ ( pack<T,N,sse_> const& a0
                                    , pack<T,N,sse_> const& a1
                                    , case_<1> const &
                                    ) BOOST_NOEXCEPT
  {
    return _mm_unpackhi_epi32(a0,a1);
  }

  template < class T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,sse_> interleave_second_ ( pack<T,N,sse_> const& a0
                                    , pack<T,N,sse_> const& a1
                                    , case_<2> const &
                                    ) BOOST_NOEXCEPT
  {
    return _mm_unpackhi_epi16(a0,a1);
  }

  template < class T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,sse_> interleave_second_ ( pack<T,N,sse_> const& a0
                                    , pack<T,N,sse_> const& a1
                                    , case_<3> const &
                                    ) BOOST_NOEXCEPT
  {
    return _mm_unpackhi_epi8(a0,a1);
  }

  template < typename T, std::size_t N
           , typename =  typename std::enable_if<std::is_integral<T>::value>
  >
  pack<T,N,sse_> interleave_second_ ( pack<T,N,sse_> const& a0
                                    , pack<T,N,sse_> const& a1
                                    ) BOOST_NOEXCEPT

  {
    return vi_interleave_second_(a0, a1, size_picker<T>());
  }

} } }

#endif
