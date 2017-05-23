//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_AND_HPP_INCLUDED

#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/traits.hpp>

namespace boost { namespace simd { namespace detail
{

  // Native implementation
  template<typename T1, typename T2, std::size_t N, std::size_t M
           , typename = typename std::enable_if<sizeof(T1)*N == sizeof(T2)*M>::type>
  BOOST_FORCEINLINE pack<T1,N> bitwise_and_ ( BOOST_SIMD_SUPPORTS(simd_)
                                            , pack<T1,N> const& a
                                            , pack<T2,M> const& b
                                            ) BOOST_NOEXCEPT
  {
    return bitwise_and(a, simd::bitwise_cast<T1>(b));
  }

  // Emulated implementation
  template<typename T1, typename T2, std::size_t N, std::size_t M
           , typename = typename std::enable_if<sizeof(T1)*N == sizeof(T2)*M>::type>
  BOOST_FORCEINLINE pack<T1,N,simd_emulation_> bitwise_and_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                            , pack<T1,N,simd_emulation_> const& a
                                                            , pack<T2,M,simd_emulation_> const& b
                                                            ) BOOST_NOEXCEPT
  {
    return map_to( simd::bitwise_and, a, b);
  }
} } }

#endif

