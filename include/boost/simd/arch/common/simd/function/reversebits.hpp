//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REVERSEBITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REVERSEBITS_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/simd/detail/meta/convert_helpers.hpp>
#include <boost/simd/detail/meta/size_picker.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_reversebits_(pack<T,N> const& a0
                , detail::case_<0> const&) BOOST_NOEXCEPT // 64bits

  {
    using p_t = pack<T,N>;
    using ui_t = as_ui_t<p_t>;
    ui_t v = bitwise_cast<ui_t>(a0);
    const ui_t m1  = ui_t(0x5555555555555555ull); //binary: 0101...
    const ui_t m2  = ui_t(0x3333333333333333ull); //binary: 00110011..
    const ui_t m4  = ui_t(0x0f0f0f0f0f0f0f0full); //binary:  4 zeros,  4 ones ...
    const ui_t m8  = ui_t(0x00ff00ff00ff00ffull); //binary:  8 zeros,  8 ones ...
    const ui_t m16 = ui_t(0x0000ffff0000ffffull); //binary:  16 zeros,  16 ones ...
    const ui_t m32 = ui_t(0x00000000ffffffffull); //binary:  32 zeros,  32 ones ...
    // swap odd and even bits
    v = bitwise_or(bitwise_and(shr(v, 1), m1), shift_left(bitwise_and(v, m1), 1));
    // swap consecutive pairs
    v = bitwise_or(bitwise_and(shr(v, 2), m2), shift_left(bitwise_and(v, m2), 2));
    // swap nibbles ...
    v = bitwise_or(bitwise_and(shr(v, 4), m4), shift_left(bitwise_and(v, m4), 4));
    // swap bytes ...
    v = bitwise_or(bitwise_and(shr(v, 8), m8), shift_left(bitwise_and(v, m8), 8));
    // swap shorts ...
    v = bitwise_or(bitwise_and(shr(v, 16), m16), shift_left(bitwise_and(v, m16), 16));
    // swap ints ...
    v = bitwise_or(bitwise_and(shr(v, 32), m32), shift_left(bitwise_and(v, m32), 32));
    return bitwise_cast<p_t>(v);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_reversebits_(pack<T,N> const& a0
                       , detail::case_<1> const&) BOOST_NOEXCEPT // 32bits

  {
    using p_t = pack<T,N>;
    using ui_t = as_ui_t<p_t>;
    ui_t v = bitwise_cast<ui_t>(a0);
    const ui_t m1  = ui_t(0x55555555); //binary: 0101...
    const ui_t m2  = ui_t(0x33333333); //binary: 00110011..
    const ui_t m4  = ui_t(0x0f0f0f0f); //binary:  4 zeros,  4 ones ...
    const ui_t m8  = ui_t(0x00ff00ff); //binary:  8 zeros,  8 ones ...
    const ui_t m16 = ui_t(0x0000ffff); //binary:  16 zeros,  16 ones ...
    // swap odd and even bits
    v = bitwise_or(bitwise_and(shr(v, 1), m1), shift_left(bitwise_and(v, m1), 1));
    // swap consecutive pairs
    v = bitwise_or(bitwise_and(shr(v, 2), m2), shift_left(bitwise_and(v, m2), 2));
    // swap nibbles ...
    v = bitwise_or(bitwise_and(shr(v, 4), m4), shift_left(bitwise_and(v, m4), 4));
    // swap bytes ...
    v = bitwise_or(bitwise_and(shr(v, 8), m8), shift_left(bitwise_and(v, m8), 8));
    // swap shorts ...
    v = bitwise_or(bitwise_and(shr(v, 16), m16), shift_left(bitwise_and(v, m16), 16));
    return bitwise_cast<p_t>(v);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_reversebits_(pack<T,N> const& a0
                , detail::case_<2> const&) BOOST_NOEXCEPT // 16bits

  {
    using p_t = pack<T,N>;
    using ui_t = as_ui_t<p_t>;
    ui_t v = bitwise_cast<ui_t>(a0);
    const ui_t m1  = ui_t(0x5555); //binary: 0101...
    const ui_t m2  = ui_t(0x3333); //binary: 00110011..
    const ui_t m4  = ui_t(0x0f0f); //binary:  4 zeros,  4 ones ...
    const ui_t m8  = ui_t(0x00ff); //binary:  8 zeros,  8 ones ...
    // swap odd and even bits
    v = bitwise_or(bitwise_and(shr(v, 1), m1), shift_left(bitwise_and(v, m1), 1));
    // swap consecutive pairs
    v = bitwise_or(bitwise_and(shr(v, 2), m2), shift_left(bitwise_and(v, m2), 2));
    // swap nibbles ...
    v = bitwise_or(bitwise_and(shr(v, 4), m4), shift_left(bitwise_and(v, m4), 4));
    // swap bytes ...
    v = bitwise_or(bitwise_and(shr(v, 8), m8), shift_left(bitwise_and(v, m8), 8));
    return bitwise_cast<p_t>(v);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_reversebits_(pack<T,N> const& a0
                , detail::case_<3> const&) BOOST_NOEXCEPT // 8bits

  {
    using p_t = pack<T,N>;
    using ui_t = as_ui_t<p_t>;
    ui_t v = bitwise_cast<ui_t>(a0);
    const ui_t m1  = ui_t(0x55); //binary: 0101...
    const ui_t m2  = ui_t(0x33); //binary: 00110011..
    const ui_t m4  = ui_t(0x0f); //binary:  4 zeros,  4 ones ...
    // swap odd and even bits
    v = bitwise_or(bitwise_and(shr(v, 1), m1), shift_left(bitwise_and(v, m1), 1));
    // swap consecutive pairs
    v = bitwise_or(bitwise_and(shr(v, 2), m2), shift_left(bitwise_and(v, m2), 2));
    // swap nibbles ...
    v = bitwise_or(bitwise_and(shr(v, 4), m4), shift_left(bitwise_and(v, m4), 4));
    return bitwise_cast<p_t>(v);
  }

  // Native implementation
  template<typename T, std::size_t N
           , typename =  typename std::enable_if<std::is_integral<T>::value>::type
           >
  BOOST_FORCEINLINE pack<T,N>
  reversebits_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T,N> const& a
               ) BOOST_NOEXCEPT
  {
    return v_reversebits_( a, size_picker<T>());
  }

  // Emulated implementation
  template<typename T, std::size_t N
           , typename =  typename std::enable_if<std::is_integral<T>::value>::type
           >
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  reversebits_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T,N,simd_emulation_> const& a
               ) BOOST_NOEXCEPT
  {
    return map_to(simd::reversebits, a);
  }

} } }

#endif

