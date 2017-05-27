//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ASEC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ASEC_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/detail/constant/pio_2lo.hpp>
#include <boost/simd/function/acsc.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/acsc.hpp>

namespace boost { namespace simd { namespace detail
{

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> vasec_( pack<T,N> const& a, std::false_type const&) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    p_t tmp =  (Pio_2<p_t>()-acsc(a)) +  Pio_2lo<p_t>();
    return if_zero_else(is_equal(a, One<p_t>()), tmp);
  }

  template<typename T,std::size_t N>
  BOOST_FORCEINLINE
  pack<float,N> vasec_(pack<T,N> const& a, std::true_type const&) BOOST_NOEXCEPT
  {
    using p_t = pack<T, N>;
    return (bs::Pio_2<p_t>()-bs::acsc(a));
  }

  // Native implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N> asec_(BOOST_SIMD_SUPPORTS(simd_)
                  , pack<T,N> const& a) BOOST_NOEXCEPT
  {
    return vasec_(a,std::is_same<T, float>());
  }

  // Emulated implementation
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE
  pack<T,N,simd_emulation_> asec_ ( BOOST_SIMD_SUPPORTS(simd_)
                                  , pack<T,N,simd_emulation_> const& a
                                  ) BOOST_NOEXCEPT
  {
    return map_to(simd::asec, a);
  }

} } }

#endif
