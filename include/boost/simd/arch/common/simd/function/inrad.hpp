//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INRAD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INRAD_HPP_INCLUDED

#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/constant/deginrad.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N
           , typename =  typename std::enable_if<is_floating_point<T>::value>
  >
  BOOST_FORCEINLINE auto
  inrad_(BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N> const& a) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    a*Deginrad(as(a))
  )

  // Emulated implementation
    template<typename T, std::size_t N
           , typename =  typename std::enable_if<is_floating_point<T>::value>
  >
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  inrad_ ( BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N,simd_emulation_> const& a
         ) BOOST_NOEXCEPT
  {
    return map_to(simd::inrad, a);
  }

} } }


#endif
