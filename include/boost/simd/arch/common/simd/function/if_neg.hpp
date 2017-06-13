//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_NEG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_NEG_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/if_else.hpp>

namespace boost { namespace simd { namespace detail
{
 template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE
  pack<U,N> if_neg_(BOOST_SIMD_SUPPORTS(simd_)
                            , pack<T,N> const& a0
                            , pack<U,N> const& a1 ) BOOST_NOEXCEPT
  {
    return if_else(a0, -a1, a1);
  }

  // Emulated implementation
  template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE
  pack<U,N,simd_emulation_> if_neg_ ( BOOST_SIMD_SUPPORTS(simd_)
                                    , pack<T,N,simd_emulation_> const& a0
                                    , pack<U,N,simd_emulation_> const& a1
                                    ) BOOST_NOEXCEPT
  {
    return map_to(simd::if_neg, a0, a1);
  }

  //mixed
  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N>
  if_neg_(BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N> const & a0
         , U  a1) BOOST_NOEXCEPT
  {
    using p_t = pack<U, N>;
    return if_neg_(a0, p_t(a1));
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N>
  if_neg_(BOOST_SIMD_SUPPORTS(simd_)
         , T  a0
         , pack<U,N> const & a1) BOOST_NOEXCEPT
  {
    return a0 ? -a1 : a1;
  }

} } }

#endif

