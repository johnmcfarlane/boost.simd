//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_PREV_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_PREV_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/next.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> v_prev_( pack<T,N> const& a0
                   , std::true_type const &) BOOST_NOEXCEPT
  {
    return if_nan_else(is_nan(a0), -bs::next(-a0));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> v_prev_( pack<T,N> const& a0
                   , std::false_type const &) BOOST_NOEXCEPT
  {
    return dec(a0);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> prev_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return v_prev_(a0, std::is_floating_point<T>());
  }

 // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> prev_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::prev, a);
  }

} } }

#endif

