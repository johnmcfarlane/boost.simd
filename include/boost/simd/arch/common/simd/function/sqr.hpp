//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SQR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SQR_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/constant/sqrtvalmax.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>

#ifdef USE_UBSAN
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/dispatch/meta/as_unsigned.hpp>
#endif

namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  sqr_(BOOST_SIMD_SUPPORTS(simd_)
      , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return a0*a0;
  }

 // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  sqr_ ( BOOST_SIMD_SUPPORTS(simd_)
       , pack<T,N,simd_emulation_> const& a
       ) BOOST_NOEXCEPT
  {
    return map_to(simd::sqr, a);
  }

  //================================================================================================
  // saturated_ decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  svsqr_( pack<T,N> a0
        , std::false_type const&) BOOST_NOEXCEPT //integral
  {
    using p_t =  pack<T,N>;
    // workaround for UBSan
#ifdef USE_UBSAN
    using u_t =  ui_t<p_t>;
    return if_else(is_greater(saturated_(abs)(a0), bs::Sqrtvalmax<p_t>()),
                   bs::Valmax<p_t>(), bitwise_cast<p_t>(sqr(bitwise_cast<u_t>(a0))));
#else
    return if_else(is_greater(saturated_(abs)(a0), bs::Sqrtvalmax<p_t>()),
                   bs::Valmax<p_t>(), sqr(a0));
#endif
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  svsqr_(pack<T,N> a0
        , std::true_type const&) BOOST_NOEXCEPT //floating
  {
    return sqr(a0);
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  sqr_(BOOST_SIMD_SUPPORTS(simd_)
      , saturated_tag const &
      , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return svsqr_(a0, std::is_floating_point<T>());
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  sqr_ ( BOOST_SIMD_SUPPORTS(simd_)
       , saturated_tag const&
       , pack<T,N,simd_emulation_> const& a
       ) BOOST_NOEXCEPT
  {
    return map_to(saturated_(simd::sqr), a);
  }

} } }

#endif

