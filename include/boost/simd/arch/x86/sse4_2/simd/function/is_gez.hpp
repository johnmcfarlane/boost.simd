//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_2_SIMD_FUNCTION_IS_GEZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_2_SIMD_FUNCTION_IS_GEZ_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/logical_not.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/meta/as_logical.hpp>


namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE as_logical_t<pack<std::int64_t,2,sse_>>
  is_gez_ ( BOOST_SIMD_SUPPORTS(sse4_2_)
          , pack<std::int64_t,2,sse_> const& a0
          ) BOOST_NOEXCEPT

  {
    using p_t = pack<std::int64_t,2,sse_>;
    p_t tmp = _mm_cmpgt_epi64(Zero<p_t>(), a0);
    return logical_not(tmp);
  }

} } }

#endif
