//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_INSERT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_INSERT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/nsm.hpp>

namespace boost { namespace simd { namespace detail
{
  template< typename T, typename I, typename V
          // SFINAE out if Integral is not modeling IntegralConstant
          , typename = nsm::constant<typename I::value_type,I::value>
          >
  BOOST_FORCEINLINE void insert_( BOOST_SIMD_SUPPORTS(sse2_)
                                , pack<T,8,sse_>& dst, I const &, V const & value
                                ) BOOST_NOEXCEPT
  {
    enum { index = I::value };
    dst = _mm_insert_epi16(dst, value, index);
  }
} } }

#endif
