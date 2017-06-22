//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TOUINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TOUINT_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/is_greater_equal.hpp>
#include <boost/simd/function/is_ngez.hpp>
#include <boost/simd/function/saturate.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular case
  template<typename T, std::size_t N> //floating
  BOOST_FORCEINLINE ui_t<pack<T,N>>
  v_touint_(pack<T,N> a0
           , detail::case_<0> const&) BOOST_NOEXCEPT
  {
    using p_t  = pack<T,N>;
    using s_it =  si_t<T>;
    using u_it =  ui_t<pack<T,N>>;
    p_t sign_f = inc(p_t(Valmax<s_it>()));
    u_it sign_i = inc(u_it(Valmax<s_it>()));
    return if_else(is_less(a0, sign_f)
                  , bitwise_cast<u_it>(toint(a0))
                  , bitwise_cast<u_it>(toint(a0 - sign_f)) + sign_i
                  );
  }

  template<typename T, std::size_t N> //signed
  BOOST_FORCEINLINE  ui_t<pack<T,N>>
  v_touint_(pack<T,N> a
          , detail::case_<1> const&) BOOST_NOEXCEPT
  {
    using r_t =  ui_t<pack<T,N>>;
    return bitwise_cast<r_t>(a);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE  ui_t<pack<T,N>>
  v_touint_(pack<T,N> a
          , detail::case_<2> const&) BOOST_NOEXCEPT
  {
    return a;
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE  ui_t<pack<T,N>>
  touint_(BOOST_SIMD_SUPPORTS(simd_)
        , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return v_touint_(a,fsu_picker<T>{});
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE ui_t<pack<T,N,simd_emulation_>>
  touint_ ( BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N,simd_emulation_> const& a
         ) BOOST_NOEXCEPT
  {
    return map_to(simd::touint, a);
  }

  //================================================================================================
  // saturated case
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE  ui_t<pack<T,N>>
  vs_touint_(pack<T,N> a0
           , detail::case_<0> const&) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    using r_t = ui_t<pack<T,N>>;
    using sr_t = ui_t<T>;
    p_t Vax = p_t(Valmax<sr_t>());
    return if_zero_else(is_ngez(a0),
                        if_else(is_greater_equal(a0, Vax), Valmax<r_t>(),
                                touint(a0)
                               )
                       );
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE  ui_t<pack<T,N>>
  vs_touint_(pack<T,N> a0
           , detail::case_<1> const&) BOOST_NOEXCEPT
  {
    using r_t = ui_t<pack<T,N>>;
    return bitwise_cast<r_t>(saturate<r_t>(a0));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE ui_t<pack<T,N>>
  vs_touint_(pack<T,N> a0
           , detail::case_<2> const&) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE  ui_t<pack<T,N>>
  touint_(BOOST_SIMD_SUPPORTS(simd_)
        , saturated_tag const &
        , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return vs_touint_(a,fsu_picker<T>{});
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE ui_t<pack<T,N,simd_emulation_>>
  touint_ ( BOOST_SIMD_SUPPORTS(simd_)
         , saturated_tag const &
         , pack<T,N,simd_emulation_> const& a
         ) BOOST_NOEXCEPT
  {
    return map_to(saturated_(simd::touint), a);
  }
} } }

#endif
