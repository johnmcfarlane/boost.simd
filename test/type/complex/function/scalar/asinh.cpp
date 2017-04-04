//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/asinh.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex asinh on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::asinh(c1), bs::complex<T>(-1.316957896924816708625046347308, 1.5707963267948966192313216916398), 0.5);
  STF_ULP_EQUAL( bs::asinh(c2), bs::complex<T>(- 2.2999140408792696499557896306632, 0.91761685335147865575986274867017), 1.5);
  STF_ULP_EQUAL( bs::asinh(c3), bs::complex<T>(1.0612750619050356520330189162136, 0.66623943249251525510400489597779), 0.5);
}


STF_CASE_TPL ( "complex asinh limits",   STF_IEEE_TYPES)
{
  using bs::asinh;
  using cT =  bs::complex<T> ;

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
   STF_ULP_EQUAL(bs::asinh(cT(bs::Nan  <T>(), bs::Zero<T>())), cT(bs::Nan <T>(), bs::Zero<T>()), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::One  <T>(), bs::Inf <T>())), cT(bs::Inf<T>(),  bs::Pio_2<T>()), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::One  <T>(), bs::Nan <T>())), cT(bs::Nan<T>(),  bs::Nan<T>()), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::Inf  <T>(), bs::One <T>())), cT(bs::Inf <T>(), bs::Zero<T>()), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::Inf  <T>(), bs::Inf<T>())),  cT(bs::Inf <T>(), bs::Pi<T>()/4), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::Inf  <T>(), bs::Nan<T>())),  cT(bs::Inf <T>(), bs::Nan<T>()), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::Nan  <T>(), bs::One<T>())),  cT(bs::Nan <T>(), bs::Nan<T>()), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::Nan  <T>(), bs::Inf<T>())),  cT(bs::Minf <T>(), bs::Nan<T>()), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::Nan  <T>(), bs::Nan<T>())),  cT(bs::Nan <T>(), bs::Nan<T>()), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::One  <T>(), -bs::Inf <T>())), cT(bs::Inf<T>(),  -bs::Pio_2<T>()), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::One  <T>(), -bs::Nan <T>())), cT(bs::Nan<T>(),  -bs::Nan<T>()), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::Inf  <T>(), -bs::One <T>())), cT(bs::Inf <T>(), -bs::Zero<T>()), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::Inf  <T>(), -bs::Inf<T>())),  cT(bs::Inf <T>(), -bs::Pi<T>()/4), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::Inf  <T>(), -bs::Nan<T>())),  cT(bs::Inf <T>(), -bs::Nan<T>()), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::Nan  <T>(), -bs::One<T>())),  cT(bs::Nan <T>(), -bs::Nan<T>()), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::Nan  <T>(), -bs::Inf<T>())),  cT(bs::Minf <T>(), -bs::Nan<T>()), 0.75);
   STF_ULP_EQUAL(bs::asinh(cT(bs::Nan  <T>(), -bs::Nan<T>())),  cT(bs::Nan <T>(), -bs::Nan<T>()), 0.75);
#endif
   STF_ULP_EQUAL(bs::asinh(cT(bs::Zero<T>(),  bs::Zero<T>())), cT(bs::Zero<T>(), bs::Zero<T>()), 0.75);
}
