//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DEC_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/is_not_equal.hpp>
#include <boost/simd/function/if_dec.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{

  //================================================================================================
  // regular cases
   // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> dec_(BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return a-One(as(a));
  }


  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_> dec_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                   , pack<T,N,simd_emulation_> const& a
                                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::dec, a);
  }


//================================================================================================
  // saturated_ decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> svdec_(pack<T,N> a
                                    , std::true_type const&) BOOST_NOEXCEPT //floating
  {
    // saturated dec on real values is merely dec
    return dec(a);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> svdec_(pack<T,N> a
                                    , std::false_type const&) BOOST_NOEXCEPT//integral
  {
    // saturated dec on  integral values takes care of Valmin
    return if_dec(is_not_equal(a, Valmin(as(a))), a);
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> dec_ (BOOST_SIMD_SUPPORTS(simd_)
                 , saturated_tag const&, pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return svdec_(a,std::is_floating_point<T>{});
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_> dec_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                   , saturated_tag const&
                                                   , pack<T,N,simd_emulation_> const& a
                                                   ) BOOST_NOEXCEPT
  {
    return map_to(saturated_(simd::dec), a);
  }

} } }

#endif
