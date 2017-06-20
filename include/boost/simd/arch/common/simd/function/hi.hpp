//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_HI_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_HI_HPP_INCLUDED

#include <boost/simd/function/interleave_odd.hpp>
#include <boost/simd/function/lo.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/detail/dispatch/meta/downgrade.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <type_traits>


namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  ui_t<pack<T, N>> vhi_(pack<T,N> const& a0
                       , std::true_type const &) BOOST_NOEXCEPT
  {
    using s_t = ui_t<T>;
    s_t half_bits = sizeof(s_t)*(CHAR_BIT/2);
    return lo( shr(a0, half_bits) );
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  ui_t<pack<T, N>> vhi_(pack<T,N> const& a0
                       , std::false_type const &) BOOST_NOEXCEPT
  {
    using result_t = ui_t<pack < T, N>>;
    using down_t = bd::downgrade_t<result_t>;
#if BOOST_ENDIAN_BIG_BYTE
    return bitwise_cast<result_t>(interleave_even(Zero<down_t>(), bitwise_cast<down_t>(a0)));
#else
    return bitwise_cast<result_t>(interleave_odd(bitwise_cast<down_t>(a0), Zero<down_t>()));
#endif
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  ui_t<pack<T, N>> hi_(BOOST_SIMD_SUPPORTS(cpu_)
                      , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return vhi_(a, nsm::bool_< sizeof(T)== 1>());
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  ui_t<pack<T, N, simd_emulation_>>
  hi_(BOOST_SIMD_SUPPORTS(cpu_)
     , pack<T,N, simd_emulation_> const& a) BOOST_NOEXCEPT
  {
    return map_to(simd::hi, a);
  }

} } }


#endif
