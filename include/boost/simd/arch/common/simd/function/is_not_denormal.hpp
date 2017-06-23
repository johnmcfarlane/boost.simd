//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_NOT_DENORMAL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_NOT_DENORMAL_HPP_INCLUDED

#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/exponentbits.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/is_not_less.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE as_logical_t<pack<T,N>>
  v_is_not_denormal_ ( pack<T,N> const& a0
                     , std::true_type const &
                     ) BOOST_NOEXCEPT
  {
    return logical_or(is_eqz(a0), is_greater(abs(a0), smallestposval(as(a0))));  // perhaps better but doexnot compile yet : logical_or(is_eqz(a0), is_nez(exponentbits(a0)));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto v_is_not_denormal_ ( pack<T,N> const&
                  , std::false_type const &
                  ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    (True<pack<T,N>>())
  )

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_not_denormal_ ( BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N> const& a
                ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    v_is_not_denormal_(a, std::is_floating_point<T>())
  )

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto is_not_denormal_ ( BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N,simd_emulation_> const& a
                ) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to( simd::is_not_denormal, a)
  )

} } }


#endif
