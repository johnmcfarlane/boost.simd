//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/acos.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <iomanip>
#include <boost/math/complex/acos.hpp>
#include <boost/simd/constant/four.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <boost/simd/constant/three.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex acos on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::acos(c1), bs::complex<T>(1.5707963267948966192313216916398, -1.4436354751788103424932767402731), 0.5);
  STF_ULP_EQUAL( bs::acos(c2), bs::complex<T>(2.2047801924340733355501188067039, -2.3055090312434769420418359381334), 0.5);
  STF_ULP_EQUAL( bs::acos(c3), bs::complex<T>(0.90455689430238136412731679566196, -1.0612750619050356520330189162136), 0.5);
}

STF_CASE_TPL( "Complex acos on T", STF_IEEE_TYPES)
{
  bs::complex<T> c1(2, 0);
  STF_ULP_EQUAL( bs::acos(c1), bs::cmplx::acos(T(2)), 0.5);
}

STF_CASE_TPL ( "Complex acos limits",   STF_IEEE_TYPES)
{
  using bs::acos;
  using c_t = bs::complex<T>;
  using s_t = std::complex<T>;


  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(bs::acos(c_t(bs::Nan <T>(),  bs::Zero<T>())), c_t(bs::Nan <T>(), bs::Nan<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Nan  <T>(), bs::One<T>())),  c_t(bs::Nan <T>(), bs::Nan<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Nan  <T>(), bs::Inf<T>())),  c_t(bs::Nan <T>(), -bs::Inf<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Nan  <T>(), bs::Nan<T>())),  c_t(bs::Nan <T>(), bs::Nan<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Zero <T>(), bs::Nan <T>())), c_t(bs::Pio_2<T>(), bs::Nan<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::One  <T>(), bs::Nan <T>())), c_t(bs::Nan<T>(),  bs::Nan<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Inf  <T>(), bs::Nan<T>())),  c_t(bs::Nan <T>(), bs::Minf<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::One  <T>(), bs::Inf <T>())), c_t(bs::Pio_2<T>(), -bs::Inf<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Inf  <T>(), bs::One <T>())), c_t(bs::Zero<T>(), bs::Minf <T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Inf  <T>(), bs::Inf<T>())),  c_t(bs::Pi<T>()/bs::Four<T>(), bs::Minf <T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::Nan  <T>(), bs::One<T>())),  c_t(bs::Nan <T>(), bs::Nan<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::Nan  <T>(), bs::Inf<T>())),  c_t(bs::Nan <T>(), -bs::Inf<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::Nan  <T>(), bs::Nan<T>())),  c_t(bs::Nan <T>(), bs::Nan<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::Zero <T>(), bs::Nan <T>())), c_t(bs::Pio_2<T>(), bs::Nan<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::One  <T>(), bs::Nan <T>())), c_t(bs::Nan<T>(),  bs::Nan<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::Inf  <T>(), bs::Nan<T>())),  c_t(bs::Nan <T>(), bs::Minf<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::One  <T>(), bs::Inf <T>())), c_t(bs::Pio_2<T>(), bs::Minf<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::Inf  <T>(), bs::One <T>())), c_t(bs::Pi<T>(), -bs::Inf <T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::Inf  <T>(), bs::Inf<T>())),  c_t(bs::Three<T>()*bs::Pi<T>()/bs::Four<T>(), bs::Minf <T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Nan  <T>(), bs::One<T>())),  c_t(std::acos(s_t(bs::Nan  <T>(), bs::One<T>()))),  1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Nan  <T>(), bs::Inf<T>())),  c_t(std::acos(s_t(bs::Nan  <T>(), bs::Inf<T>()))),  1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Nan  <T>(), bs::Nan<T>())),  c_t(std::acos(s_t(bs::Nan  <T>(), bs::Nan<T>()))),  1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Zero <T>(), bs::Nan <T>())), c_t(std::acos(s_t(bs::Zero <T>(), bs::Nan <T>()))), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::One  <T>(), bs::Nan <T>())), c_t(std::acos(s_t(bs::One  <T>(), bs::Nan <T>()))), 1.0);


  STF_ULP_EQUAL(bs::acos(c_t(bs::One  <T>(), bs::Inf <T>())), c_t(std::acos(s_t(bs::One  <T>(), bs::Inf <T>()))), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Inf  <T>(), bs::One <T>())), c_t(std::acos(s_t(bs::Inf  <T>(), bs::One <T>()))), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Inf  <T>(), bs::Inf<T>())),  c_t(std::acos(s_t(bs::Inf  <T>(), bs::Inf<T>()))),  1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::Nan  <T>(), bs::One<T>())), c_t(std::acos(s_t(-bs::Nan  <T>(), bs::One<T>()))),    1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::Nan  <T>(), bs::Inf<T>())), c_t(std::acos(s_t(-bs::Nan  <T>(), bs::Inf<T>()))),    1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::Nan  <T>(), bs::Nan<T>())), c_t(std::acos(s_t(-bs::Nan  <T>(), bs::Nan<T>()))),    1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::One  <T>(), bs::Inf <T>())),c_t(std::acos(s_t(-bs::One  <T>(), bs::Inf <T>()))),   1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::Inf  <T>(), bs::One <T>())),c_t(std::acos(s_t(-bs::Inf  <T>(), bs::One <T>()))),   1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::Inf <T>(), bs::Inf<T>())),  c_t(std::acos(s_t(-bs::Inf  <T>(), bs::Inf<T>()))),   1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::One  <T>(), bs::Nan <T>())),c_t(std::acos(s_t(-bs::One  <T>(), bs::Nan <T>()))),   1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::Zero <T>(), bs::Nan <T>())),c_t(std::acos(s_t(-bs::Zero <T>(), bs::Nan <T>()))),   1.0);

  STF_ULP_EQUAL(bs::acos(c_t(bs::Inf  <T>(), bs::Nan<T>())),  c_t(bs::Nan<T>(), bs::Minf   <T>()),   1.0);
  STF_ULP_EQUAL(bs::acos(c_t(-bs::Inf <T>(), bs::Nan<T>())),  c_t(bs::Nan<T>(), bs::Minf   <T>()),   1.0);


#endif
  STF_ULP_EQUAL(bs::acos(c_t(bs::Zero<T>(),  bs::Zero<T>())), c_t(bs::Pio_2<T>(), bs::Zero<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Mzero<T>(),  bs::Zero<T>())), c_t(bs::Pio_2<T>(), bs::Zero<T>()), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(bs::One  <T>(), bs::One <T>())),   c_t(0.904556894302381, -1.061275061905036), 2.5);
  STF_ULP_EQUAL(bs::acos(c_t(bs::One  <T>(), bs::Mone <T>())),  c_t(0.904556894302381,  1.061275061905036), 2.5);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Mone  <T>(), bs::One <T>())),  c_t(2.237035759287412, -1.061275061905036), 2.5);
  STF_ULP_EQUAL(bs::acos(c_t(bs::Mone  <T>(), bs::Mone <T>())), c_t(2.237035759287412,  1.061275061905036), 2.5);

  STF_ULP_EQUAL(bs::acos(c_t(0.5, -0.5)),  c_t(std::acos(s_t(0.5, -0.5))), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(1, 1)),       c_t(std::acos(s_t(1, 1))), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(1, 10)),      c_t(std::acos(s_t(1, 10))), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(10, 10)),     c_t(std::acos(s_t(10, 10))), 1.0);
  STF_ULP_EQUAL(bs::acos(c_t(10, 1)),      c_t(std::acos(s_t(10, 1))), 1.0);


}
