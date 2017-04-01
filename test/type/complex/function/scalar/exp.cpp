//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/exp.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/exp_1.hpp>
#include <boost/simd/constant/minf.hpp>
#include <simd_test.hpp>
#include <iomanip>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/exp_1.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex exp on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 0);
  STF_ULP_EQUAL( bs::exp(c1), bs::complex<T>(-0.41614683654714238699756822950076, 0.90929742682568169539601986591174), 0.5);
  STF_ULP_EQUAL( bs::exp(c2), bs::complex<T>(-0.032542999640154784793933107703479, -0.037678977574865854770790450265886), 0.5);
  STF_ULP_EQUAL( bs::exp(c3), bs::complex<T>(bs::Exp_1<T>(), T(0)), 0.5);
}

STF_CASE_TPL( "Complex exp on complex<T>", STF_IEEE_TYPES)
{
  using bs::exp;
  using c_t = bs::complex<T>;

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(exp(c_t(bs::Inf<T>())), c_t(bs::Inf<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Minf<T>())), c_t(bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Nan<T>())), c_t(bs::Nan<T>(), bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Inf  <T>(), bs::Zero<T>())), c_t(bs::Inf<T>(), bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Nan  <T>(), bs::Zero<T>())), c_t(bs::Nan <T>(), bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::One  <T>(), bs::Inf <T>())), c_t(bs::Nan<T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::One  <T>(), bs::Nan <T>())), c_t(bs::Nan<T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Minf <T>(), bs::One <T>())), c_t(bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Minf <T>(), bs::Mone<T>())), c_t(bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Inf  <T>(), bs::One <T>())), c_t(bs::Inf <T>()*exp(c_t(bs::Zero<T>(), bs::One <T>()))), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Inf  <T>(), bs::Mone<T>())), c_t(bs::Inf <T>()*exp(c_t(bs::Zero<T>(), bs::Mone<T>()))), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Minf <T>(), bs::Inf<T>())),  c_t(bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Inf  <T>(), bs::Inf<T>())),  c_t(bs::Nan <T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Minf <T>(), bs::Nan<T>())),  c_t(bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Inf  <T>(), bs::Nan<T>())),  c_t(bs::Nan <T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Nan  <T>(), bs::One<T>())),  c_t(bs::Nan <T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Nan  <T>(), bs::Nan<T>())),  c_t(bs::Nan <T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::One  <T>(), -bs::Inf <T>())), c_t(bs::Nan<T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::One  <T>(), -bs::Nan <T>())), c_t(bs::Nan<T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Minf <T>(), -bs::One <T>())), c_t(bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Minf <T>(), -bs::Mone<T>())), c_t(bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Inf  <T>(), -bs::One <T>())), c_t(bs::Inf <T>()*exp(c_t(bs::Zero<T>(), -bs::One <T>()))), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Inf  <T>(), -bs::Mone<T>())), c_t(bs::Inf <T>()*exp(c_t(bs::Zero<T>(), -bs::Mone<T>()))), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Minf <T>(), -bs::Inf<T>())),  c_t(bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Inf  <T>(), -bs::Inf<T>())),  c_t(bs::Nan <T>(), -bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Minf <T>(), -bs::Nan<T>())),  c_t(bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Inf  <T>(), -bs::Nan<T>())),  c_t(bs::Nan <T>(), -bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Nan  <T>(), -bs::One<T>())),  c_t(bs::Nan <T>(), -bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Nan  <T>(), -bs::Nan<T>())),  c_t(bs::Nan <T>(), -bs::Nan<T>()), 0.5);
#endif
  STF_ULP_EQUAL(exp(c_t(bs::Mone<T>())), c_t(bs::One<T>()/bs::Exp_1<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::One<T>())), c_t(bs::Exp_1<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Zero<T>())), c_t(bs::One<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(0, bs::Pi<T>())),  c_t(bs::Mone<T>()), 1.0);
  STF_ULP_EQUAL(exp(c_t(bs::Zero<T>(),  bs::Zero<T>())), c_t(bs::One<T>()), 0.5);
  STF_ULP_EQUAL(exp(c_t(bs::Mzero<T>(), bs::Zero<T>())), c_t(bs::One<T>()), 0.5);
}
