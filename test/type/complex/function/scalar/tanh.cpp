//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/tanh.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/minf.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex tanh on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::tanh(c1), bs::complex<T>(0.0, -2.1850398632615189916433061023137), 0.5);
  STF_ULP_EQUAL( bs::tanh(c2), bs::complex<T>(-1.0007095360672329393295854724042, 0.0049082580674960602590787869299328), 0.5);
  STF_ULP_EQUAL( bs::tanh(c3), bs::complex<T>( 1.083923327338694543475752061212, 0.27175258531951171652884372249859), 1.0);
}



