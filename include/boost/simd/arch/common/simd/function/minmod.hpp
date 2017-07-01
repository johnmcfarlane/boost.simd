//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MINMOD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MINMOD_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/if_else_zero.hpp>
#include <boost/simd/function/is_nltz.hpp>
#include <boost/simd/function/min.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>


namespace boost { namespace simd { namespace detail
{
  //regular
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_minmod_( pack<T,N> const & a0
           , pack<T,N> const & a1
           , case_<0> const &) BOOST_NOEXCEPT
  {
    return  simd::min(a0,a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_minmod_( pack<T,N> const & a0
           , pack<T,N> const & a1
           , case_<1> const &) BOOST_NOEXCEPT
  {
    return if_else_zero(is_gez(bitwise_xor(a0, a1)),simd::min(a0, a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_minmod_( pack<T,N> const & a0
           , pack<T,N> const & a1
           , case_<2> const &) BOOST_NOEXCEPT
  {
    return if_else_zero(is_nltz(a0*a1), bs::pedantic_(bs::min)(a0, a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  minmod_(BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N> const & a0
         , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    return v_minmod_(a1, a0, fsu_picker<T>());
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  minmod_(BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N> const & a0
         , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return minmod(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  minmod_(BOOST_SIMD_SUPPORTS(simd_)
         , T const & a0
         , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return minmod(p_t(a0), a1);
  }
  // regular emulated
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  minmod_(BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N,simd_emulation_> const & a0
         , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT
  {
    return map_to(minmod, a0, a1);
  }

} } }

#endif
