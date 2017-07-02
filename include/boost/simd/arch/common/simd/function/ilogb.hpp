//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ILOGB_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ILOGB_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/exponent.hpp>
#include <boost/simd/function/group.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/split.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/function/tofloat.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/pack_cast.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <cmath>

namespace boost { namespace simd { namespace detail
{
   // regular
  template<typename T, std::size_t N>
   BOOST_FORCEINLINE as_i_t<pack<T,N>>
   silogb_( pack<T,N> const & a0, std::true_type const &) BOOST_NOEXCEPT //floating
   {
   return if_else(is_inf(a0), Valmax<as_i_t<pack<T,N>>>(), exponent(a0));
   }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_i_t<pack<T,N>>
  ssilogb_( pack<T,N> const & a0, std::true_type const &) BOOST_NOEXCEPT //large integral
  {
      return bitwise_cast<as_i_t<pack<T,N>>>(ilogb(pack_cast<as_f_t<T>>(a0)));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_i_t<pack<T,N>>
  ssilogb_( pack<T,N> const & a0, std::false_type const &) BOOST_NOEXCEPT //small integral 1 or 2 split
  {
    auto s0 = split(a0);
    return bitwise_cast<as_i_t<pack<T,N>>>(group(ilogb(s0[0]), ilogb(s0[1])));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_i_t<pack<T,N>>
  silogb_( pack<T,N> const & a0, std::false_type const &) BOOST_NOEXCEPT //integral
  {
    return ssilogb_(a0, nsm::bool_<sizeof(T) >= 4>());
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_i_t<pack<T,N>>
  ilogb_(BOOST_SIMD_SUPPORTS(simd_), pack<T,N> const & a0) BOOST_NOEXCEPT
  {
    return silogb_(a0, std::is_floating_point<T>());
  }

  // emulation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_i_t<pack<T,N,simd_emulation_>>
  ilog2_(BOOST_SIMD_SUPPORTS(simd_), pack<T,N,simd_emulation_> const & a0) BOOST_NOEXCEPT
  {
    return map_to(simd::ilogb, a0);
  }

  //pedantic
  template<typename T, std::size_t N,
           typename = typename std::enable_if<std::is_floating_point<T>::value>
  >
  BOOST_FORCEINLINE as_i_t<pack<T,N>>
  ilogb_(BOOST_SIMD_SUPPORTS(simd_)
        , pedantic_tag const &
        , pack<T,N> const & a0) BOOST_NOEXCEPT
  {
    using result_t = as_i_t<pack<T,N>>;
    result_t fp_ilogbnan(FP_ILOGBNAN);
    result_t fp_ilogb0(FP_ILOGB0);
    return if_else(is_nan(a0), fp_ilogbnan,
                   if_else(is_eqz(a0), fp_ilogb0
                          , simd::ilogb(a0)));
  }

  //std
  template<typename T, std::size_t N,
           typename = typename std::enable_if<std::is_floating_point<T>::value>
  >
  BOOST_FORCEINLINE auto
  ilogb_(BOOST_SIMD_SUPPORTS(simd_)
        , std_tag const &
        , pack<T,N> const & a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to(std_(ilogb), a0)
  )

} } }

#endif

