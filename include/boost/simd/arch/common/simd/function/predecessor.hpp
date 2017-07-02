//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_PREDECESSOR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_PREDECESSOR_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/assert_utils.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/function/bitfloating.hpp>
#include <boost/simd/function/bitinteger.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/is_gez.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/if_dec.hpp>
#include <boost/assert.hpp>
#include <type_traits>
#include <boost/simd/detail/meta/convert_helpers.hpp>

namespace boost { namespace simd { namespace detail
{
  // one parameter
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_predecessor_( pack<T,N> const & a0
                , std::true_type const &) BOOST_NOEXCEPT
  {
    return if_nan_else(is_nan(a0), bitfloating(saturated_(dec)(bitinteger(a0))));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_predecessor_( pack<T,N> const & a0
                , std::false_type const &) BOOST_NOEXCEPT
  {
    return if_dec(is_not_equal(a0, Valmin(as(a0))), a0);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  predecessor_(BOOST_SIMD_SUPPORTS(simd_)
              , pack<T,N> const & a0) BOOST_NOEXCEPT
  {
    return v_predecessor_(a0, std::is_floating_point<T>());
  }

  // two parameters
  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N>
  v_predecessor_( pack<T,N> const & a0
                , pack<U,N> const & a1
                , std::false_type const &
                ) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(assert_all(is_gez(a1)), "predecessor rank must be non negative");
    return if_else( is_greater(Valmin(as(a0))+a1, a0), Valmin(as(a0)), a0-a1);
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N>
  v_predecessor_( pack<T,N> const & a0
                , pack<U,N> const & a1
                , std::true_type const &
                ) BOOST_NOEXCEPT
  {
    BOOST_ASSERT_MSG(assert_all(is_gez(a1)), "predecessor rank must be non negative");
    return if_nan_else(is_nan(a0), bitfloating(saturated_(minus)(bitinteger(a0), a1)));

  }

  template<typename T, typename U, std::size_t N
           , typename =  typename std::enable_if<std::is_integral<U>::value && sizeof(T) == sizeof(U)>
  >
  BOOST_FORCEINLINE pack<T,N>
  predecessor_( BOOST_SIMD_SUPPORTS(simd_)
              , pack<T,N> const & a0
              , pack<U,N> const & a1
              ) BOOST_NOEXCEPT
  {
    return v_predecessor_(a0, a1, std::is_floating_point<T>());
  }

  // Emulated implementation
  template<typename T, std::size_t N, typename U
           , typename =  typename std::enable_if<std::is_integral<U>::value && sizeof(T) == sizeof(U)>
  >
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_>
  predecessor_ ( BOOST_SIMD_SUPPORTS(simd_)
               , pack<T,N,simd_emulation_> const& a0
               , pack<U,N,simd_emulation_> const& a1
               ) BOOST_NOEXCEPT
  {
    return map_to(simd::predecessor, a0, a1);
  }

  //==============================================================================
  // mixed calls
  // regular
  template<typename T, std::size_t N,  typename U
           , typename = typename std::enable_if<std::is_integral<U>::value &&
                                                 (sizeof(T) == sizeof(U))>
  >
  BOOST_FORCEINLINE pack<T,N>
  predecessor_(BOOST_SIMD_SUPPORTS(simd_)
              ,  pack<T,N> const & a0
              , U a1
              ) BOOST_NOEXCEPT
  {
    using pi_t = pack<as_i_t<U>,N>;
    return  predecessor(a0, pi_t(a1));
  }

  template<typename T, std::size_t N,  typename U
           , typename = typename std::enable_if<std::is_integral<U>::value &&
                                                (sizeof(T) == sizeof(U))>
  >
  BOOST_FORCEINLINE pack<T,N>
  predecessor_(BOOST_SIMD_SUPPORTS(simd_)
              , T a0
              , pack<U,N> const & a1
              ) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return  predecessor(p_t(a0), a1);
  }

} } }

#endif
