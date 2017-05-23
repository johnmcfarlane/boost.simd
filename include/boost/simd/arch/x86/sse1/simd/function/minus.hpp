//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_MINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_MINUS_HPP_INCLUDED
#include <boost/simd/pack.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template < typename T
             , typename = typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE pack<T,4, sse_> minus_ ( BOOST_SIMD_SUPPORTS(sse1_)
                                           , pack<T,4, sse_> const& a0
                                           , pack<T,4, sse_> const& a1
                                           ) BOOST_NOEXCEPT
  {
    return _mm_sub_ps(a0,a1);
  }
} } }

#endif



