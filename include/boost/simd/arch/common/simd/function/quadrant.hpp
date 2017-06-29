//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_QUADRANT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_QUADRANT_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/floor.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/quarter.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/tofloat.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  // Native implementation
  template< std::size_t N>
  BOOST_FORCEINLINE pack<float,N>
  quadrant_(BOOST_SIMD_SUPPORTS(simd_)
           , pack<float,N> const& a0) BOOST_NOEXCEPT
  {
    return tofloat(quadrant(toint(a0)));
  }

  template< std::size_t N>
  BOOST_FORCEINLINE pack<double,N>
  quadrant_(BOOST_SIMD_SUPPORTS(simd_)
           , pack<double,N> const& a0) BOOST_NOEXCEPT
  {
    auto a = a0*Quarter(as(a0));
    return (a-floor(a))*Four(as(a0));
  }

  template< typename T, std::size_t N,
            typename =  typename std::enable_if<is_integral<T>::value>
  >
  BOOST_FORCEINLINE pack<T,N>
  quadrant_(BOOST_SIMD_SUPPORTS(simd_)
           , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return a0&Three(as(a0));
  }

} } }

#endif

