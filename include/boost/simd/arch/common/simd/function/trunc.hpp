//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TRUNC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_TRUNC_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/constant/maxflint.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/pack_cast.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/function/std.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vtrunc_( pack<T,N> const& a0, std::true_type const &) BOOST_NOEXCEPT
  {
    using p_t =  pack<T,N>;
    return if_else( bs::abs(a0) < Maxflint<p_t>(), raw_(trunc)(a0) , a0);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vtrunc_( pack<T,N> const& a0, std::false_type const &) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> trunc_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return vtrunc_(a0, std::is_floating_point<T>());
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> trunc_ ( BOOST_SIMD_SUPPORTS(simd_)
                                   , pack<T,N,simd_emulation_> const& a
                                   ) BOOST_NOEXCEPT
  {
    return map_to(simd::trunc, a);
  }

  //================================================================================================
  // std decorator
  template<typename T, std::size_t N
           , typename = typename std::enable_if<is_floating_point<T>::value>::type>
  BOOST_FORCEINLINE
  auto trunc_(BOOST_SIMD_SUPPORTS(simd_)
             , std_tag const&
             , pack<T,N> const& a0) BOOST_NOEXCEPT_DECLTYPE_BODY
  (
    map_to(std_(simd::trunc), a0)
  )

  //================================================================================================
  // raw  decorator
    template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vrtrunc_( pack<T,N> const& a0, std::true_type const &) BOOST_NOEXCEPT
  {
//    return  pack_cast<T>(pack_cast<si_t<T>>(a0));
    return  pack_cast<T>(toint(a0));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vrtrunc_( pack<T,N> const& a0, std::false_type const &) BOOST_NOEXCEPT
  {
    return a0;
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> trunc_(BOOST_SIMD_SUPPORTS(simd_)
                  , raw_tag const &
                  , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return vrtrunc_(a0, std::is_floating_point<T>());
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> trunc_ ( BOOST_SIMD_SUPPORTS(simd_)
                                   , raw_tag const&
                                   , pack<T,N,simd_emulation_> const& a
                                   ) BOOST_NOEXCEPT
  {
    return map_to(raw_(simd::trunc), a);
  }

} } }

#endif
