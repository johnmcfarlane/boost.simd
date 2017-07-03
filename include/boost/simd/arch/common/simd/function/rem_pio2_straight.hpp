//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REM_PIO2_STRAIGHT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REM_PIO2_STRAIGHT_HPP_INCLUDED

#include <boost/simd/detail/pack.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/constant/pio2_1.hpp>
#include <boost/simd/detail/constant/pio2_2.hpp>
#include <boost/simd/detail/constant/pio2_3.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_one_else_zero.hpp>
#include <utility>

namespace boost { namespace simd { namespace detail
{
  template<typename T, std::size_t N>
  BOOST_FORCEINLINE std::pair <pack<T,N>, pack<T,N>>
  rem_pio2_straight_(BOOST_SIMD_SUPPORTS(simd_)
                    , pack<T,N> const& x) BOOST_NOEXCEPT
  {
    using p_t = pack<T,N>;
    auto test = x > Pio_4<p_t>();
    p_t xr = x-Pio2_1<p_t>();
    xr -= Pio2_2<p_t>();
    xr -= Pio2_3<p_t>();
    return {if_one_else_zero(test),if_else(test, xr, x)};
  }

  struct rem_straight_aux1
  {
    template < typename T>
    BOOST_FORCEINLINE T
    operator()(const T & x) const  BOOST_NOEXCEPT
    {
      return if_one_else_zero(x > Pio_4<T>());
    }
  };

  struct rem_straight_aux2
  {
    template < typename T>
    BOOST_FORCEINLINE T
    operator()(const T & x, const T & test) const  BOOST_NOEXCEPT
    {
      T xr = x-Pio2_1<T>();
      xr -= Pio2_2<T>();
      xr -= Pio2_3<T>();
      return if_else(test, xr, x);
    }
  };

  template<typename T, std::size_t N>
  BOOST_FORCEINLINE std::pair < pack<T,N,simd_emulation_>, pack<T,N,simd_emulation_>>

  rem_pio2_straight_(BOOST_SIMD_SUPPORTS(simd_)
                    , pack<T,N,simd_emulation_> const& x) BOOST_NOEXCEPT
  {
    auto test = map_to(rem_straight_aux1(), x);
    auto xr   = map_to(rem_straight_aux2(), x, test);
    return {test, xr};
  }

} } }


#endif
