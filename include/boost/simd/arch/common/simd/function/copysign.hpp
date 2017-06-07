//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COPYSIGN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COPYSIGN_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/signnz.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  scopysign_( pack<T,N> const & a0
            , pack<T,N> const & a1, std::true_type const &) BOOST_NOEXCEPT
  {
    return bitwise_or(bitofsign(a1), bs::abs(a0));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  scopysign_( pack<T,N> const & a0
            , pack<T,N> const & a1, std::false_type const &) BOOST_NOEXCEPT
  {
    return saturated_(bs::abs)(a0)*bs::signnz(a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  copysign_(BOOST_SIMD_SUPPORTS(simd_)
           , pack<T,N> const & a0
           , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    return scopysign_(a0, a1, std::is_floating_point<T>());
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  copysign_(BOOST_SIMD_SUPPORTS(simd_)
           , pack<T,N> const & a0
           , T const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return copysign_(a0, p_t(a1));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  copysign_(BOOST_SIMD_SUPPORTS(simd_)
           , T const & a0
           , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return copysign_(p_t(a0), a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  copysign_(BOOST_SIMD_SUPPORTS(simd_)
           , pack<T,N,simd_emulation_> const & a0
           , pack<T,N,simd_emulation_> const & a1) BOOST_NOEXCEPT
  {
    return map_to(copysign, a0, a1);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  copysign_(BOOST_SIMD_SUPPORTS(simd_)
           , std_tag const &
           , pack<T,N> const & a0
           , pack<T,N> const & a1) BOOST_NOEXCEPT
  {
    return map_to(std_(copysign), a0, a1);
  }

} } }
#endif

