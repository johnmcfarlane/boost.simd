//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_EQZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_EQZ_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/shuffle.hpp>
#include <boost/simd/detail/dispatch/meta/downgrade.hpp>

namespace boost { namespace simd { namespace detail
{

  BOOST_FORCEINLINE pack<logical<std::int64_t>,2,sse_>
  is_eqz_ ( BOOST_SIMD_SUPPORTS(sse2_)
          , pack<std::int64_t,2,sse_> const& a
          ) BOOST_NOEXCEPT
  {
    using p_t = pack<std::int64_t,2,sse_>;
    using l_t = as_logical_t<p_t>;
    using d_t = pack<std::int32_t,4,sse_>;

    const d_t tmp1 = simd::bitwise_cast<d_t>(is_eqz(bs::bitwise_cast<d_t>(a)));
    const d_t tmp2 = shuffle<1,0,3,2>(tmp1);
    return bs::bitwise_cast<l_t>(bitwise_and(tmp1, tmp2));
  }


} } }

#endif
