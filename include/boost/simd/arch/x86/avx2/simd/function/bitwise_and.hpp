//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>

namespace boost { namespace simd { namespace ext
{
  template< typename T, std::size_t N
          , typename = typename tt_::enable_if<tt_::is_integral<T>::value>::type
          >
  BOOST_FORCEINLINE pack<T,N,avx_> bitwise_and_( BOOST_SIMD_SUPPORTS(avx2_)
                                               , pack<T,N,avx_> const& a0
                                               , pack<T,N,avx_> const& a1
                                               ) BOOST_NOEXCEPT
  {
    return _mm256_and_si256(a0, a1);
  }

} } }

#endif
