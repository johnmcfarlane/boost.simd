//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NEGATE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NEGATE_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/sign.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  namespace bs = boost::simd;

  //================================================================================================
  // regular case
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_negate_( pack<T,N> a0
           , pack<T,N> a1
           , std::true_type const&) BOOST_NOEXCEPT
  {
    return a0*sign(a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_negate_( pack<T,N> a0
           , pack<T,N> a1
           , std::false_type const&) BOOST_NOEXCEPT
  {
    return if_else_zero(is_nez(a1), a0);
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  negate_(BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N> const& a0
         , pack<T,N> const& a1) BOOST_NOEXCEPT
  {
    return v_negate_(a0, a1, std::is_signed<T>{});
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  negate_ ( BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N,simd_emulation_> const& a0
          , pack<T,N,simd_emulation_> const& a1
          ) BOOST_NOEXCEPT
  {
    return map_to(simd::negate, a0, a1);
  }

} } }

#endif

