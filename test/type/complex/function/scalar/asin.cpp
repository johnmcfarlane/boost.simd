//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/asin.hpp>
#include <boost/simd/type/complex/function/acos.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/sin.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <iomanip>
#include <boost/math/complex/asin.hpp>
namespace bs = boost::simd;

STF_CASE_TPL( "Complex asin on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1), c4(2, 0);
  STF_ULP_EQUAL( bs::asin(c1), bs::complex<T>(0, 1.4436354751788103424932767402731), 0.5);
  STF_ULP_EQUAL( bs::asin(c2), bs::complex<T>(- 0.63398386563917671631879711506414, 2.3055090312434769420418359381334), 0.5);
  STF_ULP_EQUAL( bs::asin(c3), bs::complex<T>(0.66623943249251525510400489597779, 1.0612750619050356520330189162136), 0.5);
  STF_ULP_EQUAL( bs::asin(c4), bs::complex<T>(1.5707963267948966192313216916398, 1.316957896924816708625046347308), 0.5);
}

STF_CASE_TPL ( "Complex asin limits",   STF_IEEE_TYPES)
{
  using bs::asin;
  using c_t = bs::complex<T>;
  using s_t = std::complex<T>;

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::asin(c_t(bs::Nan <T>(),  bs::Zero<T>())), bs::acos(-c_t(bs::Nan <T>(),  bs::Zero<T>()) )-bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Nan  <T>(), bs::One<T>())),  bs::acos(-c_t(bs::Nan  <T>(), bs::One<T>())  )-bs::Pio_2<T>(),   2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Nan  <T>(), bs::Inf<T>())),  bs::acos(-c_t(bs::Nan  <T>(), bs::Inf<T>())  )-bs::Pio_2<T>(),   2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Nan  <T>(), bs::Nan<T>())),  bs::acos(-c_t(bs::Nan  <T>(), bs::Nan<T>())  )-bs::Pio_2<T>(),   2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Zero <T>(), bs::Nan <T>())), bs::acos(-c_t(bs::Zero <T>(), bs::Nan <T>()) )-bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::One  <T>(), bs::Nan <T>())), bs::acos(-c_t(bs::One  <T>(), bs::Nan <T>()) )-bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Inf  <T>(), bs::Nan<T>())),  c_t(bs::Nan  <T>(), bs::Inf<T>()),   2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::One  <T>(), bs::Inf <T>())), bs::acos(-c_t(bs::One  <T>(), bs::Inf <T>()) )-bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Inf  <T>(), bs::One <T>())), bs::acos(-c_t(bs::Inf  <T>(), bs::One <T>()) )-bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Inf  <T>(), bs::Inf<T>())),  bs::acos(-c_t(bs::Inf  <T>(), bs::Inf<T>())  )-bs::Pio_2<T>(),   2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::Nan  <T>(), bs::One<T>())), bs::acos(-c_t(-bs::Nan  <T>(), bs::One<T>()) )-bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::Nan  <T>(), bs::Inf<T>())), bs::acos(-c_t(-bs::Nan  <T>(), bs::Inf<T>()) )-bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::Nan  <T>(), bs::Nan<T>())), bs::acos(-c_t(-bs::Nan  <T>(), bs::Nan<T>()) )-bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::Zero <T>(), bs::Nan <T>())),bs::acos(-c_t(-bs::Zero <T>(), bs::Nan <T>()))-bs::Pio_2<T>(), 2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::One  <T>(), bs::Nan <T>())),bs::acos(-c_t(-bs::One  <T>(), bs::Nan <T>()))-bs::Pio_2<T>(), 2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::Inf  <T>(), bs::Nan<T>())), c_t(bs::Nan  <T>(), bs::Inf<T>()),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::One  <T>(), bs::Inf <T>())),bs::acos(-c_t(-bs::One  <T>(), bs::Inf <T>()))-bs::Pio_2<T>(), 2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::Inf  <T>(), bs::One <T>())),bs::acos(-c_t(-bs::Inf  <T>(), bs::One <T>()))-bs::Pio_2<T>(), 2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::Inf  <T>(), bs::Inf<T>())), bs::acos(-c_t(-bs::Inf  <T>(), bs::Inf<T>()) )-bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Nan  <T>(), bs::One<T>())),  bs::acos(-c_t(bs::Nan  <T>(), bs::One<T>())  )-bs::Pio_2<T>(),   2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Nan  <T>(), bs::Inf<T>())),  bs::acos(-c_t(bs::Nan  <T>(), bs::Inf<T>())  )-bs::Pio_2<T>(),   2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Nan  <T>(), bs::Nan<T>())),  bs::acos(-c_t(bs::Nan  <T>(), bs::Nan<T>())  )-bs::Pio_2<T>(),   2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Zero <T>(), bs::Nan <T>())), bs::acos(-c_t(bs::Zero <T>(), bs::Nan <T>()) )-bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::One  <T>(), bs::Nan <T>())), bs::acos(-c_t(bs::One  <T>(), bs::Nan <T>()) )-bs::Pio_2<T>(),  2.0);


  STF_ULP_EQUAL(bs::asin(c_t(bs::One  <T>(),  bs::Inf <T>())), bs::acos(-c_t(bs::One  <T>(),  bs::Inf <T>())) -bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Inf  <T>(),  bs::One <T>())), bs::acos(-c_t(bs::Inf  <T>(),  bs::One <T>())) -bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Inf  <T>(),  bs::Inf<T>())),  bs::acos(-c_t(bs::Inf  <T>(),  bs::Inf<T>()))  -bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::Nan  <T>(), bs::One<T>())),  bs::acos(-c_t(-bs::Nan  <T>(), bs::One<T>()))  -bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::Nan  <T>(), bs::Inf<T>())),  bs::acos(-c_t(-bs::Nan  <T>(), bs::Inf<T>()))  -bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::Nan  <T>(), bs::Nan<T>())),  bs::acos(-c_t(-bs::Nan  <T>(), bs::Nan<T>()))  -bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::One  <T>(), bs::Inf <T>())), bs::acos(-c_t(-bs::One  <T>(), bs::Inf <T>())) -bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::Inf  <T>(), bs::One <T>())), bs::acos(-c_t(-bs::Inf  <T>(), bs::One <T>())) -bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::Inf <T>(),  bs::Inf<T>())),  bs::acos(-c_t(-bs::Inf <T>(),  bs::Inf<T>()))  -bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::One  <T>(), bs::Nan <T>())), bs::acos(-c_t(-bs::One  <T>(), bs::Nan <T>())) -bs::Pio_2<T>(),  2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::Zero <T>(), bs::Nan <T>())), bs::acos(-c_t(-bs::Zero <T>(), bs::Nan <T>())) -bs::Pio_2<T>(),  2.0);

  STF_ULP_EQUAL(bs::asin(c_t(bs::Inf  <T>(), bs::Nan<T>())),  c_t(bs::Nan<T>(), bs::Inf   <T>()),   2.0);
  STF_ULP_EQUAL(bs::asin(c_t(-bs::Inf <T>(), bs::Nan<T>())),  c_t(bs::Nan<T>(), bs::Inf   <T>()),   2.0);


#endif
  STF_ULP_EQUAL(bs::asin(c_t(bs::Zero<T>(),  bs::Zero<T>())),   bs::acos(-c_t(bs::Zero<T>(),  bs::Zero<T>()))  -bs::Pio_2<T>(),2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Mzero<T>(),  bs::Zero<T>())),  bs::acos(-c_t(bs::Mzero<T>(),  bs::Zero<T>())) -bs::Pio_2<T>(),2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::One  <T>(), bs::One <T>())),   bs::acos(-c_t(bs::One  <T>(), bs::One <T>()))  -bs::Pio_2<T>(),2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::One  <T>(), bs::Mone <T>())),  bs::acos(-c_t(bs::One  <T>(), bs::Mone <T>())) -bs::Pio_2<T>(),2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Mone  <T>(), bs::One <T>())),  bs::acos(-c_t(bs::Mone  <T>(), bs::One <T>())) -bs::Pio_2<T>(),2.0);
  STF_ULP_EQUAL(bs::asin(c_t(bs::Mone  <T>(), bs::Mone <T>())), bs::acos(-c_t(bs::Mone  <T>(), bs::Mone <T>()))-bs::Pio_2<T>(),2.0);

  STF_ULP_EQUAL(bs::asin(c_t(1, 1)),       bs::acos(-c_t(1, 1))-bs::Pio_2<T>(),        2.0);
  STF_ULP_EQUAL(bs::asin(c_t(1, 10)),      bs::acos(-c_t(1, 10))-bs::Pio_2<T>(),       2.0);
  STF_ULP_EQUAL(bs::asin(c_t(10, 1)),      bs::acos(-c_t(10, 1))-bs::Pio_2<T>(),       2.0);
  STF_ULP_EQUAL(bs::asin(c_t(10, 10)),     c_t(std::asin(s_t(10, 10))),                2.0);
  STF_ULP_EQUAL(bs::asin(c_t(0.5, -0.5)),  c_t(std::asin(s_t(0.5, -0.5))),             2.0);
}

