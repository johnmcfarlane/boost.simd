//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ROR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ROR_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/shl.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_integral<U>::value, pack<T,N>>::type
  ror_(BOOST_SIMD_SUPPORTS(simd_)
      , pack<T,N> const & a0
      , pack<U,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    BOOST_ASSERT_MSG(assert_good_shift<p_t>(a1), "ror : rotation is out of range");
    U constexpr width = sizeof(T)*CHAR_BIT;
    return shr(a0, a1) | shl(a0, (width-a1) & (width-1));
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_integral<U>::value, pack<T,N>>::type
  ror_(BOOST_SIMD_SUPPORTS(simd_)
      , pack<T,N> const & a0
      , U const & a1) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(assert_good_shift<T>(a1), "ror : rotation is out of range");
    constexpr std::size_t width = sizeof(T)*CHAR_BIT-1;
    size_t n(a1);
    return (shr(a0, n)) | (shl(a0, (-n&width)));
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_integral<U>::value, pack<T,N>>::type
  ror_(BOOST_SIMD_SUPPORTS(simd_)
      , T const & a0
      , pack<U,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return ror(p_t(a0), a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  ror_(BOOST_SIMD_SUPPORTS(simd_)
      , pack<T,N,simd_emulation_> const & a0
      , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT
  {
    return map_to(ror, a0, a1);
  }

} } }

#endif

