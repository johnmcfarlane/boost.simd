//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_ZERO_ELSE_ONE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_ZERO_ELSE_ONE_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/meta/as_arithmetic.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto if_zero_else_one_(BOOST_SIMD_SUPPORTS(simd_)
                        , pack<T,N> const& a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    if_zero_else(a0,One<simd::as_arithmetic_t<pack<T,N>>>())
  )

  // Emulated implementation
  template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE
  auto if_zero_else_one_( BOOST_SIMD_SUPPORTS(simd_)
                        , pack<T,N,simd_emulation_> const& a0
                        ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to(simd::if_zero_else_one, a0)
  )

} } }

#endif

