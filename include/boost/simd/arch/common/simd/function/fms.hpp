//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FMS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FMS_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //==========================================================================
  //regular (no decorator)
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  fms_(BOOST_SIMD_SUPPORTS(simd_)
      , pack<T,N> const & a0
      , pack<T,N> const & a1
      , pack<T,N> const & a2) BOOST_NOEXCEPT
  {
    return fma(a0, a1, -a2);
  }

  //==========================================================================
  //emulation (no decorator)
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  fms_(BOOST_SIMD_SUPPORTS(simd_)
      , pack<T,N,simd_emulation_> const & a0
      , pack<T,N,simd_emulation_> const & a1
      , pack<T,N,simd_emulation_> const & a2) BOOST_NOEXCEPT
  {
    return map_to(fms, a0, a1, a2);
  }
  //==========================================================================
  //pedantic_ decorator
  template<std::size_t N, typename X>
  BOOST_FORCEINLINE pack<float,N,X>
  fms_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , pack<float,N,X> const & a0
      , pack<float,N,X> const & a1
      , pack<float,N,X> const & a2) BOOST_NOEXCEPT
  {
    return pedantic_(fma)(a0, a1, -a2);
  }

  //mixed calls
  template<typename U, typename V, typename W>
  BOOST_FORCEINLINE
  auto fms_(BOOST_SIMD_SUPPORTS(simd_)
      , U const & a0
      , V const & a1
      , W const & a2) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    fma(a0, a1, -a2)
  )

  template<typename U, typename V, typename W>
  BOOST_FORCEINLINE
  auto fms_(BOOST_SIMD_SUPPORTS(simd_)
      , pedantic_tag const &
      , U const & a0
      , V const & a1
      , W const & a2) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    pedantic_(fma)(a0, a1, -a2)
  )

 //==========================================================================
  //std decorator
  template<typename T
           , typename = typename std::enable_if<std::is_floating_point<T>::value>::type
  >
  BOOST_FORCEINLINE T
  fms_(BOOST_SIMD_SUPPORTS(simd_)
      , std_tag const&
      , T a0
      , T a1
      , T a2 ) BOOST_NOEXCEPT
  {
    return map_to(std_(fma), a0, a1, -a2);
  }

} } }


#endif
