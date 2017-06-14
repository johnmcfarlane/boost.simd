//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INC_HPP_INCLUDED

#include <boost/simd/function/saturated.hpp>
#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{

  //================================================================================================
  // regular cases
   // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> inc_(BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return a+One(as(a));
  }


  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_> inc_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                   , pack<T,N,simd_emulation_> const& a
                                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::inc, a);
  }


//================================================================================================
  // saturated_ incorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> svinc_(pack<T,N> a
                                    , std::true_type const&) BOOST_NOEXCEPT //floating
  {
    // saturated inc on real values is merely inc
    return inc(a);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> svinc_(pack<T,N> a
                                    , std::false_type const&) BOOST_NOEXCEPT//integral
  {
    // saturated inc on  integral values takes care of Valmin
    return if_inc(is_not_equal(a, Valmax(as(a))), a);
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> inc_ (BOOST_SIMD_SUPPORTS(simd_)
                 , saturated_tag const&, pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return svinc_(a,std::is_floating_point<T>{});
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_> inc_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                   , saturated_tag const&
                                                   , pack<T,N,simd_emulation_> const& a
                                                   ) BOOST_NOEXCEPT
  {
    return map_to(saturated_(simd::inc), a);
  }

} } }

#endif
