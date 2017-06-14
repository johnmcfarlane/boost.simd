//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INDEG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INDEG_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/radindeg.hpp>
#include <boost/simd/detail/constant/radindegr.hpp>
#include <boost/simd/function/fms.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N
           , typename =  typename std::enable_if<is_floating_point<T>::value>
  >
  BOOST_FORCEINLINE auto
  indeg_(BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N> const& a) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    fms(a, Radindeg(as(a)), a*Radindegr(as(a)))
  )

  // Emulated implementation
    template<typename T, std::size_t N
           , typename =  typename std::enable_if<is_floating_point<T>::value>
  >
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  indeg_ ( BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N,simd_emulation_> const& a
         ) BOOST_NOEXCEPT
  {
    return map_to(simd::indeg, a);
  }

} } }


#endif
