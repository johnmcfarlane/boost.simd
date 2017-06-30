//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_GEZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_GEZ_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/constant/zero.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE  as_logical_t<pack<std::int64_t,2,sse_>>
  is_gez_ ( BOOST_SIMD_SUPPORTS(sse2_)
          , pack<std::int64_t,2,sse_> const& a0
          ) BOOST_NOEXCEPT
  {
    using p_t = pack<std::int64_t,2,sse_>;
    using l_t = as_logical_t<p_t>;
    using d_t = pack<std::int32_t,4,sse_>;
    const d_t tmp1 = bitwise_cast<d_t>(is_gez(bitwise_cast<d_t>(a0)));
    const d_t tmp = shuffle<1,1,3,3>(tmp1);
    return bitwise_cast<l_t>(tmp);
  }

} } }

#endif
