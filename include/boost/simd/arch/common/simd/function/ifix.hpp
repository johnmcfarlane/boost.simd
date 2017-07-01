//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IFIX_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IFIX_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE auto
  vifix_( pack<T,N> const & a0
         , std::true_type const &) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    simd::saturated_(toint)(a0)
  )

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  vifix_( pack<T,N> const & a0
         , std::false_type const & ) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE auto
  ifix_(BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N> const & a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    vifix_(a0, std::is_floating_point<T>())
  )

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE auto
  ifix_(BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N,simd_emulation_> const & a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to(ifix, a0)
  )

} } }


#endif
