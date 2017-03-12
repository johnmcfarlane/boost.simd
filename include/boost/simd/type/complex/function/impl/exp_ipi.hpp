//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_EXP_IPI_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_EXP_IPI_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/sincospi.hpp>
#include <boost/simd/type/complex/function/exp.hpp>
#include <boost/simd/type/complex/function/if_else.hpp>
#include <boost/simd/type/complex/function/is_imag.hpp>
#include <boost/simd/type/complex/function/mul_i.hpp>
#include <boost/config.hpp>


namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( exp_ipi_
                          , (typename A0)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE A0 operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      using rtype =  typename A0::value_type;
      rtype c, s;
      std::tie(s, c) = sincospi(a0.real);
      rtype rho = bs::exp(-bs::Pi<rtype>()*a0.imag);
      return if_else(logical_or(is_imag(a0), a0.imag ==  bs::Inf<rtype>()),
                     A0(rho, Zero<rtype>()),
                     A0(rho*c, rho*s));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( exp_ipi_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    using result_t = cmplx::complex<A0>;
    BOOST_FORCEINLINE result_t operator()(A0 const& a0) const BOOST_NOEXCEPT
    {
      A0 c, s;
      std::tie(s, c) = bs::sincospi(a0);
      return {c, s};
    }
  };
} } }

#endif
