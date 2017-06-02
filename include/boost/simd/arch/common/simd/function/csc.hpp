//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CSC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CSC_HPP_INCLUDED

#include <boost/simd/function/restricted.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/sin.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> csc_(BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return rec(sin(a));
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> csc_ ( BOOST_SIMD_SUPPORTS(simd_)
                                 , pack<T,N,simd_emulation_> const& a
                                 ) BOOST_NOEXCEPT
  {
    return map_to(simd::csc, a);
  }

  // restricted_ decorator
  template<typename T, std::size_t N, typename X>
  BOOST_FORCEINLINE
  pack<T,N,X> csc_( BOOST_SIMD_SUPPORTS(simd_)
                  , restricted_tag const&
                  , pack<T,N,X> const& a) BOOST_NOEXCEPT
  {
    return  rec(restricted_(sin)(a));
  }

  // other tags
  template<typename T, std::size_t N, typename X, typename Tag>
  BOOST_FORCEINLINE
  pack<T,N> csc_( BOOST_SIMD_SUPPORTS(simd_)
                , pack<T,N> const& a
                , Tag const&) BOOST_NOEXCEPT
  {
    return  rec(sin(a, Tag()));
  }

} } }


#endif
