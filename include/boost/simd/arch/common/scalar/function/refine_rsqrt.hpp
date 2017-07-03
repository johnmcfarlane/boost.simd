//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REFINE_RSQRT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REFINE_RSQRT_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/fnms.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/one.hpp>

namespace boost { namespace simd { namespace detail
{
  template<typename T, typename Arch>
  BOOST_FORCEINLINE
  T refine_rsqrt_(BOOST_SIMD_SUPPORTS(Arch)
              , T const & a0, T const& x) BOOST_NOEXCEPT
  {
    // Newton-Raphson
    return fma( fnms(a0, sqr(x), One<T>()), x*Half<T>(), x);
    //return x * Half<T>() * fnms(a0, sqr(x), Three<T>());
  }

} } }

#endif

