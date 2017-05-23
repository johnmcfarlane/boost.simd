//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/pack.hpp>

namespace boost { namespace simd { namespace detail
{
  template < typename T
             , typename = typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE pack<T,4,sse_> sse_bitwise_and_( pack<T,4,sse_> const& a0
                                                   , pack<T,4,sse_> const& a1
                                                   ) BOOST_NOEXCEPT
  {
    return _mm_and_ps(a0, a1);
  }

  template< typename T1, typename T2, std::size_t M
          , typename = typename std::enable_if<sizeof(T2)*M == 128>::type
          , typename = typename std::enable_if<std::is_floating_point<T1>::value>::type
          >
  BOOST_FORCEINLINE pack<T1,4,sse_> bitwise_and_ ( BOOST_SIMD_SUPPORTS(sse1_)
                                                 , pack<T1,4,sse_> const& a
                                                 , pack<T2,M,sse_> const& b
                                                 ) BOOST_NOEXCEPT
  {
    using Type1 =  pack<float,4,sse_>;
    return sse_bitwise_and_(a, simd::bitwise_cast<Type1>(b));
  }

} } }

#endif
