//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_IS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMPL_IS_EQUAL_HPP_INCLUDED

#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/simd/type/complex/detail/hierarchy.hpp>
#include <boost/simd/logical.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( is_equal_
                          , (typename A0)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          , bs::cmplx::complex_<A0>
                          )
  {
    BOOST_FORCEINLINE auto operator()(A0 const& a0, A0 const& a1) const
    BOOST_NOEXCEPT_DECLTYPE_BODY
    (
      (a0.real == a1.real) && (a0.imag == a1.imag)
    )
  };

  BOOST_DISPATCH_OVERLOAD ( is_equal_
                          , (typename A0,typename A1)
                          , bd::cpu_
                          , bs::cmplx::complex_<A0>
                          , bd::generic_< bd::arithmetic_<A1> >
                          )
  {
    BOOST_FORCEINLINE auto operator()(A0 const& a0, A1 const& a1) const
    BOOST_NOEXCEPT_DECLTYPE_BODY
    (
      ((a0.real == a1) && (a0.imag == 0))
    )
  };

  BOOST_DISPATCH_OVERLOAD ( is_equal_
                          , (typename A0,typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::arithmetic_<A0> >
                          , bs::cmplx::complex_<A1>
                          )
  {
    BOOST_FORCEINLINE auto operator()(A0 const& a0, A1 const& a1) const
    BOOST_NOEXCEPT_DECLTYPE_BODY
    (
      ((a0 == a1.real) && (0 == a1.imag))
    )
  };
} } }

#endif
