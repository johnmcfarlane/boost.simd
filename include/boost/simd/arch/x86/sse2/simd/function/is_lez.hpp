//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_LEZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_IS_LEZ_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/meta/as_logical.hpp>


namespace boost { namespace simd { namespace detail
{
  BOOST_FORCEINLINE as_logical_t<pack<std::int64_t,2,sse_>>
  is_lez_ ( BOOST_SIMD_SUPPORTS(sse2_)
          , pack<std::int64_t,2,sse_> const& a0
          ) BOOST_NOEXCEPT
  {
    return logical_or(is_eqz(a0), is_ltz(a0));
  }

} } }

#endif
