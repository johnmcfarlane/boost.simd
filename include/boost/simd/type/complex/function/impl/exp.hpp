//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_EXP_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_EXP_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/type/complex/function/if_else.hpp>
#include <boost/simd/type/complex/function/is_real.hpp>
#include <boost/simd/function/sincos.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( exp_
                          , (typename A0)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      using rtype = typename A0::value_type;
      rtype c, s;
      std::tie(s, c) = bs::sincos(a0.imag);
      rtype rho = bs::exp(a0.real);
      return if_else(logical_or(is_real(a0), a0.real == Minf<rtype>()),
                     A0(rho, Zero<rtype>()),
                     A0(rho*c, rho*s));

    }
  };

} } }

#endif
