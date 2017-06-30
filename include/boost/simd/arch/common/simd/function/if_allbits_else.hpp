//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_ALLBITS_ELSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_ALLBITS_ELSE_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/meta/is_bitwise_logical.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/constant/allbits.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <boost/simd/function/is_nez.hpp>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular
  template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE
  pack<U,N> vif_allbits_else_( as_logical_t<pack<T,N>> const& a0
                          , pack<U,N> const& a1, std::true_type const &) BOOST_NOEXCEPT
  {
    return bitwise_or(a1, genmask(a0));
  }
   template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE
  pack<U,N> vif_allbits_else_( pack<T,N> const& a0
                             , pack<U,N> const& a1, std::true_type const &) BOOST_NOEXCEPT
  {
    return bitwise_or(a1, genmask(is_nez(a0)));
  }

  template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE
  pack<U,N> vif_allbits_else_( pack<T,N> const& a0
                             , pack<U,N> const& a1, std::false_type const &) BOOST_NOEXCEPT
  {
    return if_else(a0, Allbits(as(a1)), a1);
  }

  template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE
  pack<U,N> if_allbits_else_(BOOST_SIMD_SUPPORTS(simd_)
                            , pack<T,N> const& a0
                            , pack<U,N> const& a1 ) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return vif_allbits_else_(a0, a1, nsm::and_<simd::is_bitwise_logical<p_t>
                                              , nsm::bool_<sizeof(T) == sizeof(U)> >());
  }

  // Emulated implementation
  template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE
  pack<U,N,simd_emulation_> if_allbits_else_ ( BOOST_SIMD_SUPPORTS(simd_)
                                             , pack<T,N,simd_emulation_> const& a0
                                             , pack<U,N,simd_emulation_> const& a1
                                             ) BOOST_NOEXCEPT
  {
    return map_to(simd::if_allbits_else, a0, a1);
  }

  //mixed
  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N>
  if_allbits_else_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N> const & a0
                  , U  a1) BOOST_NOEXCEPT
  {
    using p_t = pack<U, N>;
    return if_allbits_else_(a0, p_t(a1));
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N>
  if_allbits_else_(BOOST_SIMD_SUPPORTS(simd_)
                  , T  a0
                  , pack<U,N> const & a1) BOOST_NOEXCEPT
  {
    return a0 ? Allbits(as(a1)) : a1;
  }
} } }

#endif

