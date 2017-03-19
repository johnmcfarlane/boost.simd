//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/tan.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/minf.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex tan on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::tan(c1), bs::complex<T>(0.0,  0.96402758007581688394641372410092), 0.5);
  STF_ULP_EQUAL( bs::tan(c2), bs::complex<T>(0.00018734620462947842622425563772822, 0.99935598738147314139164963032013), 0.5);
  STF_ULP_EQUAL( bs::tan(c3), bs::complex<T>( 0.27175258531951171652884372249859, 1.083923327338694543475752061212), 1.0);
}



