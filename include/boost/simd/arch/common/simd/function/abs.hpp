//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ABS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ABS_HPP_INCLUDED

#include <boost/simd/detail/traits.hpp>
#include <boost/simd/function/bitwise_notand.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/detail/constant/maxleftshift.hpp>
#include <boost/simd/constant/mzero.hpp>

namespace boost { namespace simd { namespace detail
{
  namespace bs = boost::simd;

  //================================================================================================
  // regular case


  //------------------------------------------------------------------------------------------------
  // abs on real values cleans the sign bit
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> simd_abs_( pack<T,N> a, detail::case_<0> const&
                                       ) BOOST_NOEXCEPT
  {
    return bitwise_notand(Mzero(as(a)),a);
  }

  //------------------------------------------------------------------------------------------------
  // abs on signed integral values
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> simd_abs_( pack<T,N>a, detail::case_<1> const&
                                       ) BOOST_NOEXCEPT
  {
    auto const s = shift_right(a, Maxleftshift<T>());
    return (a+s)^s;
  }

  //------------------------------------------------------------------------------------------------
  // abs on unsigned values is identity
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> simd_abs_( pack<T,N> a, detail::case_<2> const&
                                       ) BOOST_NOEXCEPT
  {
    return a;
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> abs_ ( BOOST_SIMD_SUPPORTS(simd_)
                                    , pack<T,N> const& a
                                    ) BOOST_NOEXCEPT
  {
    return simd_abs_ ( a
                     , typename detail::pick
                       < T , tt_::is_floating_point
                           , tt_::is_signed
                           , tt_::is_unsigned
                       >::type{}
                     );
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_> abs_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                   , pack<T,N,simd_emulation_> const& a
                                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::abs, a);
  }


  //================================================================================================
  // saturated_ decorator

  //------------------------------------------------------------------------------------------------
  // saturated abs on real values is merely abs
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> simd_sat_abs_(  pack<T,N> a, detail::case_<0> const&
                                           ) BOOST_NOEXCEPT
  {
    return bs::abs(a);
  }

  //------------------------------------------------------------------------------------------------
  // saturated abs on signed integral values takes care of Valmin
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> simd_sat_abs_( pack<T,N> a, detail::case_<1> const&
                                           ) BOOST_NOEXCEPT
  {
    return if_else(a == Valmin(as(a)), Valmax(as(a)), bs::abs(a));
  }

  //------------------------------------------------------------------------------------------------
  // saturated abs on unsigned values is identity
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> simd_sat_abs_( pack<T,N> a, detail::case_<2> const&
                                           ) BOOST_NOEXCEPT
  {
    return a;
  }

   // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> abs_ ( BOOST_SIMD_SUPPORTS(simd_)
                                   , saturated_tag const&
                                   , pack<T,N> const& a
                                   ) BOOST_NOEXCEPT
  {
    return simd_sat_abs_ ( a
                         , typename detail::pick
                                 < T , tt_::is_floating_point
                                     , tt_::is_signed
                                     , tt_::is_unsigned
                                 >::type{}
                                );
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_> abs_ ( BOOST_SIMD_SUPPORTS(simd_)
                                                   , saturated_tag const&
                                                   , pack<T,N,simd_emulation_> const& a
                                                   ) BOOST_NOEXCEPT
  {
    return map_to(saturated_(simd::abs), a);
  }

} } }

#endif
