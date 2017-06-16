//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ONEMINUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ONEMINUS_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/min.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular cases
   // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  oneminus_(BOOST_SIMD_SUPPORTS(simd_)
           , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return One(as(a))-a;
  }


  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  oneminus_ ( BOOST_SIMD_SUPPORTS(simd_)
            , pack<T,N,simd_emulation_> const& a
            ) BOOST_NOEXCEPT
  {
    return map_to(simd::oneminus, a);
  }

//================================================================================================
  // saturated_ decorator

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  svoneminus_(pack<T,N> a
             , case_<0> const&) BOOST_NOEXCEPT //floating
  {
    // saturated oneminus on real values is merely oneminus
    return oneminus(a);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  svoneminus_(pack<T,N> a
             , case_<1> const&) BOOST_NOEXCEPT// signed integral
  {
    // saturated oneminus on  integral values takes care of Valmin
    return if_else((a<= Valmin(as(a))+One(as(a))), Valmax(as(a)), oneminus(a));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  svoneminus_(pack<T,N> a
             , case_<2> const&) BOOST_NOEXCEPT// unsigned integral
  {
    // saturated oneminus on unsigned  integral is 0 except for 0
    return  One(as(a))-simd::min(a, One(as(a)));
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N>
  oneminus_ (BOOST_SIMD_SUPPORTS(simd_)
            , saturated_tag const&, pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return svoneminus_(a, fsu_picker<T>());
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  oneminus_ ( BOOST_SIMD_SUPPORTS(simd_)
            , saturated_tag const&
            , pack<T,N,simd_emulation_> const& a
            ) BOOST_NOEXCEPT
  {
    return map_to(saturated_(simd::oneminus), a);
  }

} } }


#endif
