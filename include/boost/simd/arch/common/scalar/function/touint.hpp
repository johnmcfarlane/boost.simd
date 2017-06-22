//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TOUINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_TOUINT_HPP_INCLUDED

#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/is_ngez.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  ui_t<T> s_touint_( T a0
           , std::true_type const &) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T >
  BOOST_FORCEINLINE
  ui_t<T> s_touint_( T a0
           , std::false_type) BOOST_NOEXCEPT
  {
   return a0;
  }

  template<typename T>
  BOOST_FORCEINLINE
  ui_t<T> touint_(BOOST_SIMD_SUPPORTS(cpu_)
         , T a) BOOST_NOEXCEPT
  {
    return s_touint_(a, std::is_floating_point<T>());
  }

  //================================================================================================
  // saturated_ decorator
  template<typename T>  //floating
  BOOST_FORCEINLINE ui_t<T>
  s_touint_(T a0
          , detail::case_<0> const&) BOOST_NOEXCEPT
  {
    using r_t =  ui_t<T>;
    if (is_ngez(a0)) return Zero<r_t>();
    if (a0 >= Valmax<r_t>()) return Valmax<r_t>();
    return r_t(a0);
  }

  template<typename T>         //signed
  BOOST_FORCEINLINE ui_t<T>
  s_touint_(T a
          , detail::case_<1> const&) BOOST_NOEXCEPT
  {
    using r_t =  ui_t<T>;
    return r_t(saturate<r_t>(a));
  }

  template<typename T>
  BOOST_FORCEINLINE ui_t<T>     //unsigned
  s_touint_(T a
          , detail::case_<2> const&) BOOST_NOEXCEPT
  {
    return a;
  }

  template<typename T>
  BOOST_FORCEINLINE ui_t<T>
  touint_( BOOST_SIMD_SUPPORTS(cpu_)
        , saturated_tag const&
        , T const& a) BOOST_NOEXCEPT
  {
    return s_touint_(a, fsu_picker<T>{});
  }

} } }

#endif
