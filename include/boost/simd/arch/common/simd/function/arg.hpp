//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ARG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ARG_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#ifndef BOOST_SIMD_NO_NANS
#include <boost/simd/function/if_allbits_else.hpp>
#include <boost/simd/function/is_nan.hpp>
#endif
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
 {
  //================================================================================================
  // regular (no decorator)

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> arg_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return if_else_zero(is_negative(a0),Pi<T>());
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> arg_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::arg, a);
  }

  //================================================================================================
  // pedantic_ decorator

  // Native implementation
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<T,N,X> arg_( BOOST_SIMD_SUPPORTS(simd_)
                   , pedantic_tag const&
                   , pack<T,N,X> const& a) BOOST_NOEXCEPT
  {
    T r = if_else_zero(is_negative(a),Pi<T>());
#ifndef BOOST_SIMD_NO_NANS
    return if_allbits_else(is_nan(a),r);
#else
    return r;
#endif
  }

   // Emulated implementation
   template<typename T, std::size_t N>
   BOOST_FORCEINLINE
   pack<T,N,simd_emulation_> arg_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pedantic_tag const&
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
   {
     return map_to(pedantic_(simd::arg), a);
   }

} } }
