//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ATANH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ATANH_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/log1p.hpp>
#include <boost/simd/function/oneminus.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/oneminus.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> atanh_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    auto absa0 = bs::abs(a0);
    auto t =  absa0+absa0;
    auto z1 = oneminus(absa0);
    auto test =  is_less(absa0, Half(as(a0)));
    auto tmp = if_else(test, absa0, t)/z1;
    return bitwise_xor(bitofsign(a0), Half(as(a0))*log1p(if_else(test, fma(t,tmp,t), tmp)));
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> atanh_ ( BOOST_SIMD_SUPPORTS(simd_)
                                   , pack<T,N,simd_emulation_> const& a
                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::atanh, a);
  }

  //================================================================================================
  // raw_ decorator

  // Native implementation
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<T,N,X> atanh_( BOOST_SIMD_SUPPORTS(simd_)
                    , raw_tag const&
                    , pack<T,N,X> const& a0) BOOST_NOEXCEPT
  {
    return  Half(as(a0))*log(inc(a0)/oneminus(a0));
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> atanh_ ( BOOST_SIMD_SUPPORTS(simd_)
                                   , raw_tag const&
                                   , pack<T,N,simd_emulation_> const& a
                                   ) BOOST_NOEXCEPT
  {
    return map_to(raw_(simd::atanh), a);
  }

  //================================================================================================
  // std_ decorator

  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<T,N,X> atanh_( BOOST_SIMD_SUPPORTS(simd_)
                    , std_tag const&
                    , pack<T,N,X> const& a0) BOOST_NOEXCEPT
  {
    return  map_to(std_(atanh), a0);
  }


} } }

#endif
