//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEXTPOW2_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEXTPOW2_HPP_INCLUDED

#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/ffs.hpp>
#include <boost/simd/function/ifrexp.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/reversebits.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( nextpow2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_ < bd::unsigned_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return !a0 ? a0 : sizeof(A0)*8-ffs(reversebits(a0));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( nextpow2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_ < bd::signed_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return !a0 ? a0 : sizeof(A0)*8-ffs(reversebits(saturated_(abs)(a0)));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( nextpow2_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_ < bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE bd::as_integer_t<A0, signed> operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      auto me = pedantic_(ifrexp)(bs::abs(a0));
      return (me.mantissa == Half<A0>()) ? saturated_(dec)(me.exponent) : me.exponent;
    }
  };
} } }

#endif
