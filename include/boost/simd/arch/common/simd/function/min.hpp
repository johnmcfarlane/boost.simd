//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MIN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MIN_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/function/std.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <type_traits>


namespace boost { namespace simd { namespace detail
{
  //regular
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  min_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    return  if_else(is_less(a1, a0), a1, a0);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  min_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0
          , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return min(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  min_(BOOST_SIMD_SUPPORTS(simd_)
          , T const & a0
          , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return min(p_t(a0), a1);
  }
  // regular emulated
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  min_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N,simd_emulation_> const & a0
          , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT
  {
    return map_to(min, a0, a1);
  }

  //////////////////////////////////////////////////////////////////////////////////
  //pedantic
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  spmin_( pack<T,N> const & a0
        , pack<T,N> const & a1
        , std::true_type const &) BOOST_NOEXCEPT
  {
    return if_else(is_nan(a1), a0, bs::min(a0, a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  spmin_( pack<T,N> const & a0
        , pack<T,N> const & a1
        , std::false_type const &) BOOST_NOEXCEPT
  {
    return bs::min(a0, a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  min_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , pack<T,N> const & a0
      , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    return spmin_(a0, a1, std::is_floating_point<T>());
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  min_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , pack<T,N> const & a0
      , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return pedantic_(min)(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  min_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , T const & a0
      , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return pedantic_(min)(p_t(a0), a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  min_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , pack<T,N,simd_emulation_> const & a0
      , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT
  {
    return map_to(pedantic_(min), a0, a1);
  }

 template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  min_(BOOST_SIMD_SUPPORTS(simd_)
      , std_tag const &
      , pack<T,N> const & a0
      , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    return map_to(std::min, a0, a1);
  }

} } }

#endif

