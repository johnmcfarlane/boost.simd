//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CSCPI_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CSCPI_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/restricted.hpp>
#include <boost/simd/arch/common/detail/tags.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/sinpi.hpp>
#include <boost/config.hpp>
#include <boost/simd/meta/is_pack.hpp>

namespace boost { namespace simd { namespace detail
{
  // regular (no decorator)

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> cscpi_(BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return cscpi(a, tag::big_);
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> cscpi_ ( BOOST_SIMD_SUPPORTS(simd_)
                                 , pack<T,N,simd_emulation_> const& a
                                 ) BOOST_NOEXCEPT
  {
    return map_to(simd::cscpi, a);
  }

  // restricted_ decorator
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<T,N,X> cscpi_( BOOST_SIMD_SUPPORTS(simd_)
                  , restricted_tag const&
                  , pack<T,N,X> const& a) BOOST_NOEXCEPT
  {
    return rec(restricted_(sinpi)(a));
  }

  // other tags
  template<typename T, std::size_t N, typename X, typename Tag>
  BOOST_FORCEINLINE
  pack<T,N> cscpi_( BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N> const& a
                , Tag const&) BOOST_NOEXCEPT
  {
    return if_nan_else(is_nez(a)&&is_flint(a), rec(sinpi(a, Tag())));
  }

} } }


#endif
