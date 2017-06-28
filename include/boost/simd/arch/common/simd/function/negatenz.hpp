//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NEGATENZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NEGATENZ_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/signnz.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/meta/fsu_picker.hpp>

namespace boost { namespace simd { namespace detail
{

  //================================================================================================
  // regular case
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_negatenz_( pack<T,N> a0
             , pack<T,N> a1
             , detail::case_<0> const&) BOOST_NOEXCEPT
  {
    return bitwise_xor(bitofsign(a1), a0);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_negatenz_( pack<T,N> a0
             , pack<T,N> a1
             , detail::case_<1> const&) BOOST_NOEXCEPT
  {
    return a0*signnz(a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  v_negatenz_( pack<T,N> a0
             , pack<T,N>
             , detail::case_<2> const&) BOOST_NOEXCEPT
  {
    return a0;
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  negatenz_( BOOST_SIMD_SUPPORTS(simd_)
           , pack<T,N> const& a0
           , pack<T,N> const& a1) BOOST_NOEXCEPT
  {
    return v_negatenz_(a0, a1,fsu_picker<T>{});
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  negatenz_ ( BOOST_SIMD_SUPPORTS(simd_)
            , pack<T,N,simd_emulation_> const& a0
            , pack<T,N,simd_emulation_> const& a1
            ) BOOST_NOEXCEPT
  {
    return map_to(simd::negatenz, a0, a1);
  }

} } }


#endif
