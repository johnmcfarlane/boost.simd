//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ULPDIST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ULPDIST_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/ifrexp.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/if_zero_else.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/constant/eps.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD_IF( ulpdist_
                            , (typename A0, typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::pack_<bd::floating_<A0>, X>
                            , bs::pack_<bd::floating_<A0>, X>
                            )
  {
    inline A0 operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      auto me1  = pedantic_(ifrexp)(a0);
      auto me2  = pedantic_(ifrexp)(a1);
      auto expo = -bs::max(me1.exponent, me2.exponent);

      A0 e = if_else( me1.exponent == me2.exponent
                    , bs::abs(me1.mantissa - me2.mantissa)
                    , bs::abs( bs::pedantic_(ldexp)(a0, expo) - bs::pedantic_(ldexp)(a1, expo))
                    );

      return if_zero_else( (bs::is_nan(a0) && bs::is_nan(a1)) || (a0 == a1)
                         , e/Eps<A0>()
                         );
    }
  };
} } }

#endif
