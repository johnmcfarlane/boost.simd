//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REM_PIO2_CEPHES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REM_PIO2_CEPHES_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/function/fnms.hpp>
#include <boost/simd/function/nearbyint.hpp>
#include <boost/simd/function/quadrant.hpp>
#include <boost/simd/constant/twoopi.hpp>
#include <boost/simd/detail/constant/pio2_1.hpp>
#include <boost/simd/detail/constant/pio2_2.hpp>
#include <boost/simd/detail/constant/pio2_3.hpp>
#include <utility>

namespace boost { namespace simd { namespace detail
{
  template<typename T, typename Arch>
  BOOST_FORCEINLINE   std::pair<T, T>
  rem_pio2_cephes_(BOOST_SIMD_SUPPORTS(Arch)
                  , T const& x) BOOST_NOEXCEPT
  {
    T xi =  nearbyint(x*Twoopi<T>());
    T xr  = fnms(xi, Pio2_1<T>(), x);
    xr -= xi*Pio2_2<T>();
    xr -= xi*Pio2_3<T>();
    return {quadrant(xi), xr};
  }

} } }


#endif
