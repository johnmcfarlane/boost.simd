//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_andnot.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/pack_cast.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  //==========================================================================
  //regular
  template<typename C, typename T, std::size_t N >
  BOOST_FORCEINLINE pack<T,N>
  if_else_(BOOST_SIMD_SUPPORTS(simd_)
           , pack<C,N> const & a0
           , pack<T,N> const & a1
           , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
    as_logical_t<pack<C,N>> t = is_nez(a0);
    auto m = genmask(t);
    return bitwise_or(bitwise_and(a1,m), bitwise_andnot(a2,m));
//    return if_else(t, a1, a2);
  }

  template<typename C, typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  if_else_(BOOST_SIMD_SUPPORTS(simd_)
          , as_logical_t<pack<C,N>> const & a0
          , pack<T,N> const & a1
          , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
    auto m = genmask(a0);
    return bitwise_or(bitwise_and(a1,m), bitwise_andnot(a2,m));
  }

  //==========================================================================
  //emulation
  template<typename C, typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  if_else_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<C,N,simd_emulation_> const & a0
          , pack<T,N,simd_emulation_> const & a1
          , pack<T,N,simd_emulation_> const & a2) BOOST_NOEXCEPT
  {
    return map_to(if_else, a0, a1, a2);
   }

  template<typename C, typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  if_else_(BOOST_SIMD_SUPPORTS(simd_)
          , as_logical_t<pack<C,N,simd_emulation_>> const & a0
          , pack<T,N,simd_emulation_> const & a1
          , pack<T,N,simd_emulation_> const & a2) BOOST_NOEXCEPT
  {
    return map_to(if_else, a0, a1, a2);
   }

  //mixed calls two packs
  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<U, T>::value, pack<T,N>>::type
  if_else_(BOOST_SIMD_SUPPORTS(simd_)
          , U a0
          , pack<T,N> const & a1
          , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
    return a0 ? a1 : a2;
  }

  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<U, V>::value, pack<V,N>>::type
  if_else_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , U a1
          , pack<V,N> const & a2) BOOST_NOEXCEPT
  {
    using p_t = pack<V,N>;
    return if_else(a0, p_t(a1), a2);
  }

  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<V, U>::value, pack<U,N>>::type
  if_else_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , pack<U,N> const & a1
          , V a2) BOOST_NOEXCEPT
  {
    using p_t = pack<U,N>;
    return if_else(a0, a1, p_t(a2));
  }

  //mixed calls one packs
  // no decorator
  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<V, U>::value, pack<U,N>>::type
  if_else_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , U a1
          , V a2) BOOST_NOEXCEPT
  {
    using p_t = pack<U,N>;
    return if_else(a0, p_t(a1), p_t(a2));
  }

  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<V, T>::value, pack<T,N>>::type
  if_else_(BOOST_SIMD_SUPPORTS(simd_)
          , U a0
          , V a1
          , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return a0 ? p_t(a1) : a2;
  }

  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<V, T>::value, pack<T,N>>::type
  if_else_(BOOST_SIMD_SUPPORTS(simd_)
          , U a0
          , pack<T,N> const & a1
          , V a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return a0 ? a1 : p_t(a2);
  }

} } }

#endif
