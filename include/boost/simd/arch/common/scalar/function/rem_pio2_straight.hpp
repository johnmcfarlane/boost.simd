//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REM_PIO2_STRAIGHT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REM_PIO2_STRAIGHT_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/detail/constant/pio2_1.hpp>
#include <boost/simd/detail/constant/pio2_2.hpp>
#include <boost/simd/detail/constant/pio2_3.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <utility>

namespace boost { namespace simd { namespace detail
{

  template<typename T>
  BOOST_FORCEINLINE   std::pair<T, T>
  rem_pio2_straight_(BOOST_SIMD_SUPPORTS(cpu_)
                    , T const& x) BOOST_NOEXCEPT
  {
    if (x < Pio_4<T>()) return {Zero<T>(), x};
    T xr = x-Pio2_1<T>();
    xr -= Pio2_2<T>();
    xr -= Pio2_3<T>();
    return {One<T>(), xr};
  }

} } }


#endif
