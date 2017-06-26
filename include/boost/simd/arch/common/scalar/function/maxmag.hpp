//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MAXMAG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_MAXMAG_HPP_INCLUDED

#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  ///////////////////////////////////////////////////////////////////////
  // regular
  template<typename T>
  BOOST_FORCEINLINE T
  maxmag_(BOOST_SIMD_SUPPORTS(cpu_)
         , T a0
         , T a1) BOOST_NOEXCEPT
  {
    T aa0 = simd::abs(a0);
    T aa1 = simd::abs(a1);
    return aa0 < aa1 ? a1 : aa1 <  aa0 ? a0 : simd::max(a0, a1);
  }

} } }


#endif
