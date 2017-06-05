//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXPM1_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXPM1_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/logeps.hpp>
#include <boost/simd/detail/constant/maxlog.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/arch/common/detail/generic/expm1_kernel.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/config.hpp>
#include <cmath>
#include <boost/simd/meta/is_pack.hpp>

namespace boost { namespace simd { namespace detail
{
 //================================================================================================
  // regular (no decorator)

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> expm1_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return if_else(is_less(a0, Logeps<p_t>()),
                   Mone<p_t>(),
                   if_else(is_greater(a0, Maxlog<p_t>()),
                           Inf<p_t>(),
                           detail::expm1_kernel<p_t, T>::expm1(a0)
                          )
                  );
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> expm1_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::expm1, a);
  }

  //================================================================================================
  // std_ decorator
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<T,N,X> expm1_( BOOST_SIMD_SUPPORTS(simd_)
                   , std_tag const&
                   , pack<T,N,X> const& a) BOOST_NOEXCEPT
  {
    return map_to(std_(simd::expm1), a);
  }

} } }

#endif
