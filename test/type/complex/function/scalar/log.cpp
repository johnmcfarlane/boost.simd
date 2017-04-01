//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/log.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/pi.hpp>
#include <simd_test.hpp>
#include <iomanip>

#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/pio_4.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex log on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(-2, 0);
  STF_ULP_EQUAL( bs::log(c1), bs::complex<T>(0.69314718055994530941723212145818, 1.5707963267948966192313216916398), 0.5);
  STF_ULP_EQUAL( bs::log(c2), bs::complex<T>(1.6094379124341003746007593332262,  2.2142974355881810060341309203571), 0.5);
  STF_ULP_EQUAL( bs::log(c3), bs::complex<T>(0.69314718055994530941723212145818, 3.1415926535897932384626433832795), 0.5);
}

STF_CASE_TPL( "Complex log on T", STF_IEEE_TYPES)
{
  T r1(2), r2(-2);
  STF_ULP_EQUAL( bs::log(r1), bs::complex<T>(0.69314718055994530941723212145818, 0.0), 0.5);
  STF_ULP_EQUAL( bs::cmplx::log(r2), bs::complex<T>(0.69314718055994530941723212145818, 3.1415926535897932384626433832795), 0.5);
  STF_ULP_EQUAL( bs::log(r2), bs::Nan<T>(), 0.5);
}

STF_CASE_TPL( "More Complex log on complex<T>", STF_IEEE_TYPES)
{
  using c_t = bs::complex<T>;

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::log(c_t(bs::Minf <T>(), bs::Mone<T>())), c_t(bs::Inf<T>(), -bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Inf<T>(), 0)), c_t(bs::Inf<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Minf<T>(), 0)), c_t(bs::Inf<T>(), bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Nan<T>(), bs::Nan<T>())),  c_t(bs::Nan<T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Inf  <T>(), bs::Zero<T>())),  c_t(bs::Inf<T>(), bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Minf <T>(), bs::Zero<T>())),  c_t(bs::Inf<T>(), bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Inf  <T>(), bs::Zero<T>())),  c_t(bs::Inf <T>(), bs::Zero <T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::One  <T>(), bs::Inf <T>())), c_t(bs::Inf<T>(), bs::Pio_2<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::One  <T>(), bs::Nan <T>())), c_t(bs::Nan<T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Inf  <T>(), bs::One <T>())), c_t(bs::Inf<T>(), bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Minf <T>(), bs::One<T>())),  c_t(bs::Inf<T>(), bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Inf  <T>(), bs::One <T>())), c_t(bs::Inf <T>(), bs::Zero <T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Nan  <T>(), bs::One<T>())),  c_t(bs::Nan <T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Nan  <T>(), bs::Mone<T>())), c_t(bs::Nan <T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Nan  <T>(), bs::Nan<T>())),  c_t(bs::Nan <T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::One  <T>(), -bs::Inf <T>())), c_t(bs::Inf<T>(), -bs::Pio_2<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::One  <T>(), -bs::Nan <T>())), c_t(bs::Nan<T>(), -bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Inf  <T>(), -bs::One <T>())), c_t(bs::Inf<T>(), -bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Minf <T>(), -bs::One<T>())),  c_t(bs::Inf<T>(), -bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Inf  <T>(), -bs::One <T>())), c_t(bs::Inf <T>(), -bs::Zero <T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Nan  <T>(), -bs::One<T>())),  c_t(bs::Nan <T>(), -bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Nan  <T>(), -bs::Mone<T>())), c_t(bs::Nan <T>(), -bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Nan  <T>(), -bs::Nan<T>())),  c_t(bs::Nan <T>(), -bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Nan<T>(), bs::Zero<T>())),  c_t(bs::Nan<T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Zero<T>())), c_t(bs::Minf<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Mzero<T>())), c_t(bs::Minf<T>(), bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Zero<T>(),  bs::Zero<T>())),  c_t(bs::Minf<T>(), bs::Zero<T>()), 0.5);

#endif
  STF_ULP_EQUAL(bs::log(c_t(bs::Mone<T>())), c_t(bs::Zero<T>(), bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::One<T>())), c_t(bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(bs::log(c_t(bs::Zero<T>(), bs::One<T>())),c_t(bs::Zero<T>(), bs::Pio_2<T>()), 0.5);
}


STF_CASE_TPL( "More Complex pedantic_(log) on complex<T>", STF_IEEE_TYPES)
{
  using c_t = bs::complex<T>;

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Minf <T>(), bs::Mone<T>())), c_t(bs::Inf<T>(), -bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Inf<T>(), 0)), c_t(bs::Inf<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Minf<T>(), 0)), c_t(bs::Inf<T>(), bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Nan<T>(), bs::Nan<T>())),  c_t(bs::Nan<T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Inf  <T>(), bs::Zero<T>())),  c_t(bs::Inf<T>(), bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Minf <T>(), bs::Zero<T>())),  c_t(bs::Inf<T>(), bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Inf  <T>(), bs::Zero<T>())),  c_t(bs::Inf <T>(), bs::Zero <T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::One  <T>(), bs::Inf <T>())), c_t(bs::Inf<T>(), bs::Pio_2<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::One  <T>(), bs::Nan <T>())), c_t(bs::Nan<T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Inf  <T>(), bs::One <T>())), c_t(bs::Inf<T>(), bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Minf <T>(), bs::One<T>())),  c_t(bs::Inf<T>(), bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Inf  <T>(), bs::One <T>())), c_t(bs::Inf <T>(), bs::Zero <T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Nan  <T>(), bs::One<T>())),  c_t(bs::Nan <T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Nan  <T>(), bs::Mone<T>())), c_t(bs::Nan <T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Nan  <T>(), bs::Nan<T>())),  c_t(bs::Nan <T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::One  <T>(), -bs::Inf <T>())), c_t(bs::Inf<T>(), -bs::Pio_2<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::One  <T>(), -bs::Nan <T>())), c_t(bs::Nan<T>(), -bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Inf  <T>(), -bs::One <T>())), c_t(bs::Inf<T>(), -bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Minf <T>(), -bs::One<T>())),  c_t(bs::Inf<T>(), -bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Inf  <T>(), -bs::One <T>())), c_t(bs::Inf <T>(), -bs::Zero <T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Nan  <T>(), -bs::One<T>())),  c_t(bs::Nan <T>(), -bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Nan  <T>(), -bs::Mone<T>())), c_t(bs::Nan <T>(), -bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Nan  <T>(), -bs::Nan<T>())),  c_t(bs::Nan <T>(), -bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Nan<T>(), bs::Zero<T>())),  c_t(bs::Nan<T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Zero<T>())), c_t(bs::Minf<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Zero<T>(),  bs::Zero<T>())),  c_t(bs::Minf<T>(), bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Minf <T>(), bs::Inf<T>())),  c_t(bs::Inf <T>(), 3*bs::Pio_4<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Inf  <T>(), bs::Inf<T>())),  c_t(bs::Inf <T>(), bs::Pi<T>()/4), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Minf <T>(), -bs::Inf<T>())),  c_t(bs::Inf <T>(), -3*bs::Pio_4<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Inf  <T>(), -bs::Inf<T>())),  c_t(bs::Inf <T>(), -bs::Pi<T>()/4), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Mzero<T>())), c_t(bs::Minf<T>(), bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Nan  <T>(), bs::Inf<T>())),  c_t(bs::Inf <T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Nan  <T>(), -bs::Inf<T>())),  c_t(bs::Inf <T>(), -bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Minf <T>(), bs::Nan<T>())),  c_t(bs::Inf <T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Inf  <T>(), bs::Nan<T>())),  c_t(bs::Inf <T>(), bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Minf <T>(), -bs::Nan<T>())),  c_t(bs::Inf <T>(), -bs::Nan<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Inf  <T>(), -bs::Nan<T>())),  c_t(bs::Inf <T>(), -bs::Nan<T>()), 0.5);
#endif
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Mone<T>())), c_t(bs::Zero<T>(), bs::Pi<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::One<T>())), c_t(bs::Zero<T>()), 0.5);
  STF_ULP_EQUAL(bs::pedantic_(bs::log)(c_t(bs::Zero<T>(), bs::One<T>())),c_t(bs::Zero<T>(), bs::Pio_2<T>()), 0.5);
}


