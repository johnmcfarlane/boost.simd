//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NEXT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NEXT_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/function/bitfloating.hpp>
#include <boost/simd/function/bitinteger.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  //================================================================================================
  // regular (no decorator)
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> v_next_( pack<T,N> const& a0
                   , std::true_type const &) BOOST_NOEXCEPT
  {
    return if_else(is_equal(a0, Inf(as(a0))), a0,  bitfloating(inc(bitinteger(a0))));
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> v_next_( pack<T,N> const& a0
                   , std::false_type const &) BOOST_NOEXCEPT
  {
    return inc(a0);
  }

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> next_(BOOST_SIMD_SUPPORTS(simd_)
                 , pack<T,N> const& a0) BOOST_NOEXCEPT
  {
    return v_next_(a0, std::is_floating_point<T>());
  }

 // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> next_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::next, a);
  }

} } }

#endif


