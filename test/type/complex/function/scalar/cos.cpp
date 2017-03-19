//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/cos.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex cos on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::cos(c1), bs::complex<T>(3.7621956910836314595622134777737, 0.0), 0.5);
  STF_ULP_EQUAL( bs::cos(c2), bs::complex<T>(-27.034945603074224647694802668271, 3.8511533348117775365633371230531), 0.5);
  STF_ULP_EQUAL( bs::cos(c3), bs::complex<T>(0.83373002513114904888388539433509, -0.98889770576286509638212954089269), 1.0);
}

