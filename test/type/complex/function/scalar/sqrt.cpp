//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/sqrt.hpp>
#include <boost/simd/type/complex/function/sqr.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex sqrt on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4);
  STF_ULP_EQUAL( bs::sqrt(c1), bs::complex<T>(1, 1), 0.5);
  STF_ULP_EQUAL( bs::sqrt(c2), bs::complex<T>(1, 2), 0.5);
  STF_ULP_EQUAL( bs::pedantic_(bs::sqrt)(c1), bs::complex<T>(1, 1), 0.5);
  STF_ULP_EQUAL( bs::pedantic_(bs::sqrt)(c2), bs::complex<T>(1, 2), 0.5);
}

STF_CASE_TPL( "Complex sqrt on T", STF_IEEE_TYPES)
{
  T r0(0), r1(9), r2(-16);

  STF_EQUAL( bs::cmplx::sqrt(r0), bs::complex<T>(0,0));
  STF_EQUAL( bs::cmplx::sqrt(r1), bs::complex<T>(3,0));
  STF_EQUAL( bs::cmplx::sqrt(r2), bs::complex<T>(0,4));
}


STF_CASE_TPL ( "sqrt complex  limits", STF_IEEE_TYPES )
{
  using bs::sqrt;
  using c_t = bs::complex<T>;

  auto sqt =  bs::sqrt;

  // specific values testss
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(sqt(c_t(bs::Inf<T>())), c_t(bs::Inf<T>()), 0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Minf<T>(),bs::Zero<T>())), c_t(bs::Zero<T>(),bs::Inf<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Nan<T>(),bs::Nan<T>())),c_t(bs::Nan<T>(),bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Inf<T>(),bs::Nan<T>())),c_t(bs::Nan<T>(),bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Minf<T>())), c_t(0, bs::Inf<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Nan <T>(),bs::Inf<T>())), c_t(bs::Nan<T>(),bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::One<T>(), bs::Nan<T>())), c_t(bs::Nan<T>(),bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Inf<T>(), bs::Nan<T>())), c_t(bs::Nan<T>(),bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Minf<T>(),bs::Nan<T>())), c_t(bs::Nan<T>(),bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Nan <T>(),bs::Nan<T>())), c_t(bs::Nan<T>(),bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Minf<T>(),bs::One<T>())), c_t(bs::Zero<T>(),bs::Inf<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Minf<T>(),bs::Mone<T>())),c_t(bs::Zero<T>(),bs::Minf<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Inf<T>(),bs::Nan<T>())),  c_t(bs::Nan<T>(),bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Nan<T>(),bs::One<T>())),  c_t(bs::Nan<T>(),bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Nan<T>(),bs::Nan<T>())),  c_t(bs::Nan<T>(),bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::One<T>(), -bs::Nan<T>())), c_t(bs::Nan<T>(),-bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Inf<T>(), -bs::Nan<T>())), c_t(bs::Nan<T>(),-bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Minf<T>(),-bs::Nan<T>())), c_t(bs::Nan<T>(),-bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Nan <T>(),-bs::Nan<T>())), c_t(bs::Nan<T>(),-bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Minf<T>(),-bs::One<T>())), c_t(bs::Zero<T>(),-bs::Inf<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Minf<T>(),-bs::Mone<T>())),c_t(bs::Zero<T>(),-bs::Minf<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Inf<T>(), -bs::Nan<T>())), c_t(bs::Nan<T>(),bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Nan<T>(), -bs::One<T>())), c_t(bs::Nan<T>(),-bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Nan<T>(), -bs::Nan<T>())), c_t(bs::Nan<T>(),-bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::Nan <T>(),-bs::Inf<T>())), c_t(bs::Nan<T>(),-bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(sqt(c_t(bs::One<T>(), bs::Nan<T>())), c_t(bs::Nan<T>(),-bs::Nan<T>()),0.5);
  auto psqrt =  bs::pedantic_(bs::sqrt);
  STF_ULP_EQUAL(psqrt(c_t(bs::Inf<T>(),bs::Inf<T>())),c_t(bs::Inf<T>(),bs::Inf<T>()),0.5);
  STF_ULP_EQUAL(psqrt(c_t(bs::Zero<T>(),bs::Inf<T>())),c_t(bs::Inf<T>(),bs::Inf<T>()),0.5);
  STF_ULP_EQUAL(psqrt(c_t(bs::Nan<T>(),bs::Zero<T>())), c_t(bs::Nan<T>(),bs::Nan<T>()),0.5);
  STF_ULP_EQUAL(psqrt(c_t(bs::One<T>(), bs::Inf<T>())), c_t(bs::Inf<T>(),bs::Inf<T>()),0.5);
  STF_ULP_EQUAL(psqrt(c_t(bs::Inf<T>(), bs::Inf<T>())), c_t(bs::Inf<T>(),bs::Inf<T>()),0.5);
  STF_ULP_EQUAL(psqrt(c_t(bs::Minf<T>(),bs::Inf<T>())), c_t(bs::Inf<T>(),bs::Inf<T>()),0.5);
  STF_ULP_EQUAL(psqrt(c_t(bs::Inf<T>(), -bs::Inf<T>())), c_t(bs::Inf<T>(),-bs::Inf<T>()),0.5);
  STF_ULP_EQUAL(psqrt(c_t(bs::Minf<T>(),-bs::Inf<T>())), c_t(bs::Inf<T>(),-bs::Inf<T>()),0.5);
  STF_ULP_EQUAL(psqrt(c_t(bs::One<T>(), -bs::Inf<T>())), c_t(bs::Inf<T>(),-bs::Inf<T>()),0.5);

#endif
   STF_ULP_EQUAL(sqt(c_t(1)), c_t(1), 0);
   STF_ULP_EQUAL(sqt(c_t(bs::Mone<T>())), c_t(0, bs::One<T>()),0.5);
   STF_ULP_EQUAL(sqt(c_t(bs::One<T>())), c_t(bs::One<T>()),0.5);
   STF_ULP_EQUAL(sqt(c_t(bs::Zero<T>())), c_t(bs::Zero<T>()),0.5);
   STF_ULP_EQUAL(sqt(c_t(bs::Zero<T>(),bs::Zero<T>())), c_t(bs::Zero<T>(),bs::Zero<T>()),0.5);
   STF_ULP_EQUAL(sqt(c_t(bs::Mzero<T>(),bs::Zero<T>())),c_t(bs::Zero<T>(),bs::Zero<T>()),0.5);
   STF_ULP_EQUAL(sqt(c_t(0, 2)), c_t(1, 1), 1);
   for(T i=-5; i <=  T(5) ; i+= T(0.5))
   {
     for(T j =-5; j < T(5); j+= T(0.5))
     {
       STF_ULP_EQUAL(bs::sqr(bs::sqrt(c_t(i, j))), c_t(i, j), 10.0);
     }
   }
}
