//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COSH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COSH_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/detail/constant/maxlog.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/average.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> cosh_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    //////////////////////////////////////////////////////////////////////////////
    // if x = abs(a0) according x < Threshold e =  exp(x) or exp(x/2) is
    // respectively computed
    // *  in the first case cosh (e+rec(e))/2
    // *  in the second     cosh is (e/2)*e (avoiding undue overflow)
    // Threshold is Maxlog - Log_2
    //////////////////////////////////////////////////////////////////////////////
    using p_t =  pack<T,N>;
    p_t x = bs::abs(a0);
    auto test1 = (x > Maxlog<p_t>()-Log_2<p_t>());
    p_t fac = if_else(test1, Half<p_t>(), One<p_t>());
    p_t tmp = exp(x*fac);
    p_t tmp1 = Half<p_t>()*tmp;
    return if_else(test1, tmp1*tmp, bs::average(tmp, rec(tmp)));
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> cosh_ ( BOOST_SIMD_SUPPORTS(simd_)
                                   , pack<T,N,simd_emulation_> const& a
                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::cosh, a);
  }

  //================================================================================================
  // std_ decorator
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<T,N,X> cosh_( BOOST_SIMD_SUPPORTS(simd_)
                   , std_tag const&
                   , T const& a) BOOST_NOEXCEPT
  {
    return map_to(std::cosh, a);
  }

} } }


#endif
