//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_DEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_DEC_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/meta/is_bitwise_logical.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/if_minus.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/logical.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE
  pack<U,N> vif_dec_( pack<T,N> const& a0
                    , pack<U,N> const& a1, std::true_type const &) BOOST_NOEXCEPT
  {
    return a1 + bitwise_cast<pack<U,N>>(genmask(a0));
  }

  template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE
  pack<U,N> vif_dec_( pack<T,N> const& a0
                    , pack<U,N> const& a1, std::false_type const &) BOOST_NOEXCEPT
  {
    return if_minus(a0, a1, One(as(a1)));
  }

  template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE
  pack<U,N> if_dec_(BOOST_SIMD_SUPPORTS(simd_)
                            , pack<T,N> const& a0
                            , pack<U,N> const& a1 ) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    using test1_t = nsm::and_<simd::is_bitwise_logical<p_t>, nsm::bool_<sizeof(T) == sizeof(U)>>;
    using test_t = nsm::and_< test1_t, typename std::is_integral<T> ::type>;
    return vif_dec_(a0, a1, test_t());
  }

  // Emulated implementation
  template<typename T, typename U, std::size_t N>
  BOOST_FORCEINLINE
  pack<U,N,simd_emulation_> if_dec_ ( BOOST_SIMD_SUPPORTS(simd_)
                                    , pack<T,N,simd_emulation_> const& a0
                                    , pack<U,N,simd_emulation_> const& a1
                                    ) BOOST_NOEXCEPT
  {
    return map_to(simd::if_dec, a0, a1);
  }

  //mixed
  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N>
  if_dec_(BOOST_SIMD_SUPPORTS(simd_)
         , pack<T,N> const & a0
         , U  a1) BOOST_NOEXCEPT
  {
    using p_t = pack<U, N>;
    return if_dec_(a0, p_t(a1));
  }

  template<typename T, std::size_t N, typename U>
  BOOST_FORCEINLINE pack<T,N>
  if_dec_(BOOST_SIMD_SUPPORTS(simd_)
         , T  a0
         , pack<U,N> const & a1) BOOST_NOEXCEPT
  {
    return a0 ? dec(a1) : a1;
  }

} } }

#endif
