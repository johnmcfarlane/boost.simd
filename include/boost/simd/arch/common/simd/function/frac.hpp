//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FRAC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FRAC_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/if_allbits_else.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/function/trunc.hpp>
#include <boost/simd/constant/zero.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  vfrac_( pack<T,N> const & a0
        , std::true_type const &) BOOST_NOEXCEPT
  {
    return if_allbits_else(is_invalid(a0), a0-simd::trunc(a0));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  vfrac_( pack<T,N> const &
        , std::false_type const &) BOOST_NOEXCEPT
  {
    return Zero<pack<T,N>>();
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N>
  frac_(BOOST_SIMD_SUPPORTS(simd_)
          , pack<T,N> const & a0) BOOST_NOEXCEPT
  {
    return vfrac_(a0, std::is_floating_point<T>());
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE pack<T,N,simd_emulation_>
  frac_(BOOST_SIMD_SUPPORTS(simd_)
       , pack<T,N,simd_emulation_> const & a0) BOOST_NOEXCEPT
  {
    return map_to(frac, a0);
  }


} } }
#endif


