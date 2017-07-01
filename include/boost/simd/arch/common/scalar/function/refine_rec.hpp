//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REFINE_REC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REFINE_REC_HPP_INCLUDED
#include <boost/simd/function/fnms.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/constant/one.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, typename Arch>
  BOOST_FORCEINLINE
  T refine_rec_(BOOST_SIMD_SUPPORTS(Arch)
               , T const& a0) BOOST_NOEXCEPT
  {
    // Newton-Raphson: 1/X ~= x*(1-a0*x) + x
    return fma(fnms(x, a0, One<T>()), x, x);
  }

} } }

#endif
