//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/sqrt.hpp>
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


