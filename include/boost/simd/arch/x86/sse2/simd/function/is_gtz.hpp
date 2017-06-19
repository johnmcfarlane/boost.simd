//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_GTZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_GTZ_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/is_gez.hpp>
#include <boost/simd/function/is_nez.hpp>

namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE pack<logical<std::int64_t>,2,sse_>
  is_gtz_ ( BOOST_SIMD_SUPPORTS(sse2_)
          , pack<std::int64_t,2,sse_> const& a0
          ) BOOST_NOEXCEPT
  {
    return logical_and(is_gez(a0), is_nez(a0));
  }

} } }

#endif
