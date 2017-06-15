//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CEIL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CEIL_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/trunc.hpp>
#include <boost/simd/function/if_inc.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vceil_( pack<T,N> const& a0, std::true_type const &) BOOST_NOEXCEPT
  {
    auto d0 = trunc(a0);
    return if_inc(d0<a0,d0);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vceil_( pack<T,N> const& a0, std::false_type const &) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> ceil_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return vceil_(a0, std::is_floating_point<T>());
  }

 // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> ceil_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::ceil, a);
  }

  //================================================================================================
  // std decorator
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  auto ceil_(BOOST_SIMD_SUPPORTS(simd_)
            , std_tag const&
            , pack<T,N> const& a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to(std_(simd::ceil), a0)
  )


} } }

#endif
