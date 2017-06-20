//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_LTZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_LTZ_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/bitwise_cast.hpp>


namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE as_logical_t<pack<std::int64_t,2,sse_>>
  is_lez_ ( BOOST_SIMD_SUPPORTS(sse2_)
          , pack<std::int64_t,2,sse_> const& a0
          ) BOOST_NOEXCEPT
  {
      using i32type =  pack<std::int32_t,4,sse_>;
      using r_t =  as_logical_t<pack<std::int64_t,2,sse_>>;
      i32type that = _mm_shuffle_epi32( is_ltz(bitwise_cast<i32type>(a0))
                                      , _MM_SHUFFLE(3,3,1,1)
                                      );
      return  bitwise_cast<r_t>(that);
  }

} } }

#endif
