//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/abs.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex abs on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(0,4), r1(4,0), r2(3,3), r3(-1,0), r4(0,-1), r5(-2,-2);

  STF_ULP_EQUAL(r0.modulus(), T(4),0.5);
  STF_ULP_EQUAL(r1.modulus(), T(4),0.5);
  STF_ULP_EQUAL(r2.modulus(), bs::sqrt(T(18)),0.5);
  STF_ULP_EQUAL(r3.modulus(), T(1),0.5);
  STF_ULP_EQUAL(r4.modulus(), T(1),0.5);
  STF_ULP_EQUAL(r5.modulus(), bs::sqrt(T(8)),0.5);

  STF_ULP_EQUAL(bs::abs(r0), T(4),0.5);
  STF_ULP_EQUAL(bs::abs(r1), T(4),0.5);
  STF_ULP_EQUAL(bs::abs(r2), bs::sqrt(T(18)),0.5);
  STF_ULP_EQUAL(bs::abs(r3), T(1),0.5);
  STF_ULP_EQUAL(bs::abs(r4), T(1),0.5);
  STF_ULP_EQUAL(bs::abs(r5), bs::sqrt(T(8)),0.5);
}

