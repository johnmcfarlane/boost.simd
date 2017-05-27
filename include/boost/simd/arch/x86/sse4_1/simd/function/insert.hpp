//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_INSERT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE4_1_SIMD_FUNCTION_INSERT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/nsm.hpp>

namespace boost { namespace simd { namespace detail
{
  template< typename T, typename I, typename V
          , typename = typename std::enable_if<std::is_integral<T>::value>::type
          // SFINAE out if Integral is not modeling IntegralConstant
          , typename = nsm::constant<typename I::value_type,I::value>
          >
  BOOST_FORCEINLINE void insert_( BOOST_SIMD_SUPPORTS(sse4_1_)
                                , pack<T,4,sse_>& dst, I const &, V const & value
                                ) BOOST_NOEXCEPT
  {
    enum { index = I::value };
    dst = _mm_insert_epi32(dst, value, index);
  }

#if !defined(BOOST_MSVC)
  template< typename T, typename I, typename V
          , typename = typename std::enable_if<std::is_integral<T>::value>::type
          // SFINAE out if Integral is not modeling IntegralConstant
          , typename = nsm::constant<typename I::value_type,I::value>
          >
  BOOST_FORCEINLINE void insert_( BOOST_SIMD_SUPPORTS(sse4_1_)
                                , pack<T,2,sse_>& dst, I const &, V const & value
                                ) BOOST_NOEXCEPT
  {
    enum { index = I::value };
    dst = _mm_insert_epi64(dst, value, index);
  }
#endif

  template< typename T, typename I, typename V
          // SFINAE out if Integral is not modeling IntegralConstant
          , typename = nsm::constant<typename I::value_type,I::value>
          >
  BOOST_FORCEINLINE void insert_( BOOST_SIMD_SUPPORTS(sse4_1_)
                                , pack<T,16,sse_>& dst, I const &, V const & value
                                ) BOOST_NOEXCEPT
  {
    enum { index = I::value };
    dst = _mm_insert_epi8(dst, value, index);
  }

} } }

#endif
