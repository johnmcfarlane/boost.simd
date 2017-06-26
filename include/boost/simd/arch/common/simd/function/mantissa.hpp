//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MANTISSA_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MANTISSA_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/constant/mantissamask.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_eqz.hpp>

#include <boost/simd/detail/meta/convert_helpers.hpp>

#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/function/logical_or.hpp>
#endif


namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T, N> vmantissa_(pack<T,N> const& a0
                       , std::true_type const &) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    p_t r = bitwise_or(bitwise_and(a0,Mantissamask<p_t>()),One<p_t>());
#ifndef BOOST_SIMD_NO_INVALIDS
    return if_else(logical_or(is_invalid(a0),is_eqz(a0)),a0,r);
#else
    return if_else(is_eqz(a0),a0,r);
#endif
  }

  template<typename T, std::size_t N >
  BOOST_FORCEINLINE
  pack<T, N> vmantissa_( pack<T,N> const& a
                       , std::false_type) BOOST_NOEXCEPT
  {
    return a;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T, N>  mantissa_(BOOST_SIMD_SUPPORTS(cpu_)
                            , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return vmantissa_(a, std::is_floating_point<T>());
  }

} } }

#endif


