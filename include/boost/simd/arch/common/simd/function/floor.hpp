//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FLOOR_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FLOOR_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/trunc.hpp>
#include <boost/simd/function/if_dec.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vfloor_( pack<T,N> const& a0, std::true_type const &) BOOST_NOEXCEPT
  {
    auto d0 = trunc(a0);
    return if_dec(d0<a0,d0);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vfloor_( pack<T,N> const& a0, std::false_type const &) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> floor_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return vfloor_(a0, std::is_floating_point<T>());
  }

 // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> floor_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::floor, a);
  }

  //================================================================================================
  // std decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto floor_(BOOST_SIMD_SUPPORTS(simd_)
            , std_tag const&
            , pack<T,N> const& a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to(std_(simd::floor), a0)
  )

} } }

#endif
