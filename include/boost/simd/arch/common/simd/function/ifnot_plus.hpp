//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IFNOT_PLUS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IFNOT_PLUS_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/if_zero_else.hpp>


namespace boost { namespace simd { namespace detail
{
  //==========================================================================
  //regular
  template<typename C, typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  ifnot_plus_(BOOST_SIMD_SUPPORTS(simd_)
           , pack<C,N> const & a0
           , pack<T,N> const & a1
           , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
     return a1 + if_zero_else(a0, a2);
  }

  //==========================================================================
  //emulation
  template<typename C, typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  ifnot_plus_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<C,N,simd_emulation_> const & a0
          , pack<T,N,simd_emulation_> const & a1
          , pack<T,N,simd_emulation_> const & a2) BOOST_NOEXCEPT
  {
    return map_to(ifnot_plus, a0, a1, a2);
  }

  //mixed calls two packs
  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<U, T>::value, pack<T,N>>::type
  ifnot_plus_(BOOST_SIMD_SUPPORTS(simd_)
          , U a0
          , pack<T,N> const & a1
          , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
    return a0 ? a1 : a1+a2;
  }

  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<U, V>::value, pack<V,N>>::type
  ifnot_plus_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , U a1
          , pack<V,N> const & a2) BOOST_NOEXCEPT
  {
    using p_t = pack<V,N>;
    return ifnot_plus(a0, p_t(a1), a2);
  }

  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<V, U>::value, pack<U,N>>::type
  ifnot_plus_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , pack<U,N> const & a1
          , V a2) BOOST_NOEXCEPT
  {
    using p_t = pack<U,N>;
    return ifnot_plus(a0, a1, p_t(a2));
  }

  //mixed calls one packs
  // no decorator
  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<V, U>::value, pack<U,N>>::type
  ifnot_plus_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , U a1
          , V a2) BOOST_NOEXCEPT
  {
    using p_t = pack<U,N>;
    return ifnot_plus(a0, p_t(a1), p_t(a2));
  }

  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<V, T>::value, pack<T,N>>::type
  ifnot_plus_(BOOST_SIMD_SUPPORTS(simd_)
          , U a0
          , V a1
          , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    auto pa1 = p_t(a1);
    return a0 ? pa1 : pa1+a2;
  }

  template<typename T, std::size_t N, typename U, typename V>
  BOOST_FORCEINLINE
  typename std::enable_if<std::is_convertible<V, T>::value, pack<T,N>>::type
  ifnot_plus_(BOOST_SIMD_SUPPORTS(simd_)
          , U a0
          , pack<T,N> const & a1
          , V a2) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return a0 ? a1 :a1+ p_t(a2);
  }

} } }

#endif

