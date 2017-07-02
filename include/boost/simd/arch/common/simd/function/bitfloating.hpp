//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITFLOATING_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITFLOATING_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/signmask.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_gez.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N
           , typename = typename std::enable_if<std::is_integral<T>::value>::type
           , typename = typename std::enable_if<sizeof(T) >= 4>
  >
  BOOST_FORCEINLINE
  as_f_t<pack<T,N>> vbitfloating_( pack<T,N> const& a
                                , std::true_type const &
                                ) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    using pf_t = as_f_t<p_t>;
    auto s = bitwise_cast<p_t>(Signmask<pf_t>());
    return bitwise_cast<pf_t>(if_else(is_gez(a), a, s-a));
  }

  template<typename T, std::size_t N
           , typename = typename std::enable_if<sizeof(T) >= 4>
  >
  BOOST_FORCEINLINE
  as_f_t<pack<T,N>> vbitfloating_( pack<T,N> const& a
                                , std::false_type const &
                                ) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    using pf_t = as_f_t<p_t>;
    return simd::bitwise_cast<pf_t>(a);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_f_t<pack<T,N>> bitfloating_(BOOST_SIMD_SUPPORTS(simd_)
                               , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return vbitfloating_(a, std::is_signed<T>());
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  as_f_t<pack<T,N>> bitfloating_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::bitfloating, a);
  }

} } }

#endif

