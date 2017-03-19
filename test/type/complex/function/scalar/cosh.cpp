//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/cosh.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/minf.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex cosh on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::cosh(c1), bs::complex<T>(-0.41614683654714238699756822950076, 0), 0.5);
  STF_ULP_EQUAL( bs::cosh(c2), bs::complex<T>(- 6.5806630405511564325607441265388, 7.581552742746544353716345286538), 0.5);
  STF_ULP_EQUAL( bs::cosh(c3), bs::complex<T>(0.83373002513114904888388539433509, 0.98889770576286509638212954089269), 1.0);
}



