//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/exp_ipi.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/exp_1.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/pi.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( " exp_ipi on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(2, 0), c2(1, 1), c3(0, -1);
  STF_ULP_EQUAL( bs::exp_ipi(c1), bs::complex<T>(1, 0), 0.5);
  STF_ULP_EQUAL( bs::exp_ipi(c2), bs::complex<T>(-0.0432139182637722497744177371717, 0), 0.5);
  STF_ULP_EQUAL( bs::exp_ipi(c3), bs::complex<T>(23.1406926327792690057290863679, 0), 0.5);
}


