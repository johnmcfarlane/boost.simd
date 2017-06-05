//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXPRECNEGC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_EXPRECNEGC_HPP_INCLUDED

#include <boost/simd/function/expm1.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  // regular (no decorator)
  template<typename T>
  BOOST_FORCEINLINE
  T exprecnegc_(BOOST_SIMD_SUPPORTS(cpu_)
              , T a) BOOST_NOEXCEPT
  {
    return -expm1(-rec(a));
  }

} } }


#endif
