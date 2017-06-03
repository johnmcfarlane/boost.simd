//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DIVIDES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_DIVIDES_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_zero_else_one.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <type_traits>
#include <boost/simd/detail/meta/fsu_picker.hpp>

namespace boost { namespace simd { namespace detail
{
  // -----------------------------------------------------------------------------------------------
  // regular cases
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE pack<T,N,X> divides_ ( BOOST_SIMD_SUPPORTS(simd_)
                                         , pack<T,N,X> const& a
                                         , pack<T,N,X> const& b
                                         ) BOOST_NOEXCEPT
  {
    return map_to(simd::divides, a, b);
  }

  // -----------------------------------------------------------------------------------------------
  // saturated cases
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> sdivides_( pack<T,N> const& a, pack<T,N> const& b
                                    , case_<0> const& // IEEE saturated divides
                                    ) BOOST_NOEXCEPT
  {
    return a/b;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> sdivides_( pack<T,N> const& a0
                                       , pack<T,N> const& a1
                                       , case_<1> const& // signed integers saturated divides
                                       ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T,N>;
    using sp_t = T;
    auto iseqza1 = is_eqz(a1);
    // replace valmin/-1 by (valmin+1)/-1
    p_t x = a0 + if_zero_else_one(inc(a1) | (a0 + Valmin<p_t>()));
    // negative -> valmin
    // positive -> valmax
    const p_t x2 = bitwise_xor(Valmax<p_t>(), shift_right(x, sizeof(sp_t)*CHAR_BIT-1));
    x = if_else(logical_and(iseqza1, is_nez(x)), x2, x);
    const p_t y = if_else(iseqza1, One<p_t>(), a1);
    return x/y;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> sdivides_( pack<T,N> const& a0
                                       , pack<T,N> const& a1
                                       , case_<2> const& // unsigned integers saturated divides
                                       ) BOOST_NOEXCEPT
  {
    auto iseqza1 = is_eqz(a1);
    auto aa1 = if_else(iseqza1, One(as(a1)), a1);
    auto aa0 = if_else(iseqza1, genmask(a0), a0);
    return aa0/aa1;
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N> divides_ ( BOOST_SIMD_SUPPORTS(simd_)
                                       , saturated_tag const&, pack<T,N> const& a, pack<T,N> const& b
                                       ) BOOST_NOEXCEPT
  {
    return sdivides_ ( a, b, fsu_picker<T>());
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> divides_ ( BOOST_SIMD_SUPPORTS(simd_)
                                     , saturated_tag const&
                                     , pack<T,N,simd_emulation_> const& a
                                     , pack<T,N,simd_emulation_> const& b
                                     ) BOOST_NOEXCEPT
  {
    return map_to( saturated_(simd::divides), a, b);
  }

  //================================================================================================
  // mixed implementation T1 pack < T2 >
  template<typename T1, typename T2, std::size_t M
           , typename = typename std::enable_if<std::is_convertible<T1, T2>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T2,M> divides_ ( BOOST_SIMD_SUPPORTS(simd_)
                      , T1 a
                      , pack<T2,M> const& b
                      ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T2,M>;
    return simd::divides(p_t(a), b);
  }

  // mixed implementation pack < T1 > T2
  template<typename T1, typename T2, std::size_t N
           , typename = typename std::enable_if<std::is_convertible<T2, T1>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T1,N> divides_ ( BOOST_SIMD_SUPPORTS(simd_)
                      , pack<T1,N> const& a
                      , T2 b
                      ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T1,N>;
    return simd::divides(a, p_t(b));
  }

  // saturated mixed implementation T1 pack < T2 >
  template<typename T1, typename T2, std::size_t M
           , typename = typename std::enable_if<std::is_convertible<T1, T2>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T2, M> divides_ ( BOOST_SIMD_SUPPORTS(simd_)
                       , saturated_tag const&
                       , T1 a
                       , pack<T2,M> const& b
                       ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T2,M>;
    return saturated_(simd::divides)(p_t(a), b);
  }

  // saturated mixed implementation pack < T1 > T2
  template<typename T1, typename T2, std::size_t N
           , typename = typename std::enable_if<std::is_convertible<T2, T1>::value>::type
  >
  BOOST_FORCEINLINE
  pack<T1,N> divides_ ( BOOST_SIMD_SUPPORTS(simd_)
                      , saturated_tag const&
                      , pack<T1,N> const& a
                      , T2 b
                      ) BOOST_NOEXCEPT
  {
    using p_t =  pack<T1,N>;
    return saturated_(simd::divides)(a, p_t(b));
  }

} } }

#endif
