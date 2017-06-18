//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_GREATER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_GREATER_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE
  as_logical_t<pack<double,2,sse_>>
  is_greater_ ( BOOST_SIMD_SUPPORTS(sse2_)
              , pack<double,2,sse_> const& a0
              , pack<double,2,sse_> const& a1
              ) BOOST_NOEXCEPT
  {
    return _mm_cmpgt_pd(a0,a1);
  }

  BOOST_FORCEINLINE
  as_logical_t<pack<int8_t,16,sse_>>
  is_greater_ ( BOOST_SIMD_SUPPORTS(sse2_)
              , pack<int8_t,16,sse_> const& a0
              , pack<int8_t,16,sse_> const& a1
              ) BOOST_NOEXCEPT
  {
    return _mm_cmpgt_epi8(a0,a1);
  }

  BOOST_FORCEINLINE
  as_logical_t<pack<int16_t,8,sse_>>
  is_greater_ ( BOOST_SIMD_SUPPORTS(sse2_)
              , pack<int16_t,8,sse_> const& a0
              , pack<int16_t,8,sse_> const& a1
              ) BOOST_NOEXCEPT
  {
    return _mm_cmpgt_epi16(a0,a1);
  }

  BOOST_FORCEINLINE
  as_logical_t<pack<int32_t,4,sse_>>
  is_greater_ ( BOOST_SIMD_SUPPORTS(sse2_)
              , pack<int32_t,4,sse_> const& a0
              , pack<int32_t,4,sse_> const& a1
              ) BOOST_NOEXCEPT
  {
    return _mm_cmpgt_epi32(a0,a1);
  }

  BOOST_FORCEINLINE
  as_logical_t<pack<int64_t,2,sse_>>
  is_greater_ ( BOOST_SIMD_SUPPORTS(sse2_)
              , pack<int64_t,2,sse_> const& a0
              , pack<int64_t,2,sse_> const& a1
              ) BOOST_NOEXCEPT
  {
    using l_t = as_logical_t<pack<int64_t,2,sse_>>;
    using d_t = pack<int32_t,4,sse_>;
    using du_t = pack<uint32_t,4,sse_>;
    du_t al = shuffle<0,0,2,2>(bitwise_cast<du_t>(a0));
    du_t bl = shuffle<0,0,2,2>(bitwise_cast<du_t>(a1));
    d_t ah  = shuffle<1,1,3,3>(bitwise_cast<d_t>(a0));
    d_t bh  = shuffle<1,1,3,3>(bitwise_cast<d_t>(a1));
    return bitwise_cast<l_t>(logical_or(is_greater(ah,bh)
                                       , logical_and(is_equal(ah,bh)
                                                    , is_greater(al,bl))
                                       )
                            );
  }

  template < typename T, std::size_t N >
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_unsigned<T>::value
                          , as_logical_t<pack<T,N,sse_>>
  >::type
  is_greater_ ( BOOST_SIMD_SUPPORTS(sse2_)
              , pack<T,N,sse_> const& a0
              , pack<T,N,sse_> const& a1
              ) BOOST_NOEXCEPT
  {
    using s_t = si_t<pack<T,N,sse_>>;
    s_t sm = Signmask<s_t>();
    using r_t = as_logical_t<pack<T,N,sse_>>;
    return  bitwise_cast<r_t>( is_greater(bitwise_cast<s_t>(a0) - sm,
                                          bitwise_cast<s_t>(a1) - sm
                                         )
                             );
  }

} } }

#endif
