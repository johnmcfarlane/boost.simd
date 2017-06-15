//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_ALL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_ALL_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/genmask.hpp>

namespace boost { namespace simd { namespace detail
{
  template< typename T, std::size_t N
            , typename = typename std::enable_if<sizeof(T) == 2>::type
            >
  BOOST_FORCEINLINE bool alll_ ( BOOST_SIMD_SUPPORTS(sse2_)
                                            , pack<T,N, sse_> const& a0
                                            ) BOOST_NOEXCEPT
  {
    return _mm_movemask_epi8(genmask(a0)) == 0xFFFF;
  }

} } }

#endif
