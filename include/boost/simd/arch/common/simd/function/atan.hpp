//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ATAN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ATAN_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/arch/common/detail/simd/f_invtrig.hpp>
#include <boost/simd/arch/common/detail/simd/d_invtrig.hpp>
#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> atan_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    return invtrig_base<p_t,tag::radian_tag,tag::simd_type>::atan(a);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> atan_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::atan, a);
  }

  //================================================================================================
  // std_ decorator
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<T,N,X> atan_( BOOST_SIMD_SUPPORTS(simd_)
                   , std_tag const&
                   , pack<T,N,X> const& a) BOOST_NOEXCEPT
  {
    return map_to(std_(simd::atan), a);
  }
} } }


#endif
