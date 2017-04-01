//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/atanh.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <iomanip>
#include <boost/math/complex/atanh.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex atanh on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::atanh(c1), bs::complex<T>(0, 1.1071487177940905030170654601785), 0.5);
  STF_ULP_EQUAL( bs::atanh(c2), bs::complex<T>(- 0.11750090731143388841273425778709, 1.4099210495965755225306193844604), 0.5);
  STF_ULP_EQUAL( bs::atanh(c3), bs::complex<T>(0.40235947810852509365018983330655,  1.0172219678978513677227889615505), 0.5);
}

STF_CASE_TPL ( "atanh", STF_IEEE_TYPES)
{
  using bs::atanh;
  using c_t = bs::complex<T>;
  using s_t = std::complex<T>;



  // specific values tests
  STF_ULP_EQUAL(bs::atanh(c_t(bs::One  <T>(), bs::Inf <T>())),  c_t(boost::math::atanh(s_t(1.0, bs::Inf <T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Inf  <T>(), bs::One <T>())),  c_t(boost::math::atanh(s_t(bs::Inf <T>(), 1))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Nan  <T>(), bs::Inf<T>())),   c_t(boost::math::atanh(s_t(bs::Nan  <T>(), bs::Inf<T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Nan <T>(),  bs::Zero<T>())),  c_t(boost::math::atanh(s_t(bs::Nan <T>(),  bs::Zero<T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Inf  <T>(), bs::Nan<T>())),   c_t(boost::math::atanh(s_t(bs::Inf  <T>(), bs::Nan<T>()))) , 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Nan  <T>(), bs::One<T>())),   c_t(boost::math::atanh(s_t(bs::Nan  <T>(), bs::One<T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Nan  <T>(), bs::Nan<T>())),   c_t(boost::math::atanh(s_t(bs::Nan  <T>(), bs::Nan<T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Zero <T>(), bs::Nan <T>())),  c_t(boost::math::atanh(s_t(bs::Zero  <T>(), bs::Nan<T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::One  <T>(), bs::Nan <T>())),  c_t(boost::math::atanh(s_t(bs::One  <T>(), bs::Nan <T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Inf  <T>(), bs::Inf<T>())),   c_t(boost::math::atanh(s_t(bs::Inf  <T>(), bs::Inf<T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::One  <T>(), -bs::Inf <T>())), c_t(boost::math::atanh(s_t(1.0, -bs::Inf <T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Inf  <T>(), -bs::One <T>())), c_t(boost::math::atanh(s_t(bs::Inf <T>(), -1))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Nan  <T>(), -bs::Inf<T>())),  c_t(boost::math::atanh(s_t(bs::Nan  <T>(), -bs::Inf<T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Nan <T>(),  -bs::Zero<T>())), c_t(boost::math::atanh(s_t(bs::Nan <T>(),  -bs::Zero<T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Inf  <T>(), -bs::Nan<T>())),  c_t(boost::math::atanh(s_t(bs::Inf  <T>(), -bs::Nan<T>()))) , 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Nan  <T>(), -bs::One<T>())),  c_t(boost::math::atanh(s_t(bs::Nan  <T>(), -bs::One<T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Nan  <T>(), -bs::Nan<T>())),  c_t(boost::math::atanh(s_t(bs::Nan  <T>(), -bs::Nan<T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Zero <T>(), -bs::Nan <T>())), c_t(boost::math::atanh(s_t(bs::Zero  <T>(), -bs::Nan<T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::One  <T>(), -bs::Nan <T>())), c_t(boost::math::atanh(s_t(bs::One  <T>(), -bs::Nan <T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Inf  <T>(), -bs::Inf<T>())),  c_t(boost::math::atanh(s_t(bs::Inf  <T>(), -bs::Inf<T>()))), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(0.0, bs::Minf<T>())),             c_t(boost::math::atanh(s_t(0.0, bs::Minf<T>()))), 0);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Nan<T>(), bs::Minf<T>())),    c_t(boost::math::atanh(s_t(bs::Nan<T>(), bs::Minf<T>()))), 0);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Zero <T>(),  bs::Zero<T>())), c_t(bs::Zero <T>(), bs::Zero<T>()), 0.75);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::One  <T>(), bs::One <T>())),   c_t(0.402359478108525,  1.017221967897851), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::One  <T>(), bs::Mone <T>())),  c_t(0.402359478108525,  -1.017221967897851), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Mone  <T>(), bs::One <T>())),  c_t(-0.402359478108525,  1.017221967897851), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::Mone  <T>(), bs::Mone <T>())), c_t(-0.402359478108525,  -1.017221967897851), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::One  <T>(), 100)),            c_t(boost::math::atanh(s_t(1.0, 100.0))), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::One  <T>(), 100)),  c_t(0.0000999800053317338451627251604797, 1.56079765980832135270094509319), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(bs::One  <T>(), 2)),              c_t(boost::math::atanh(s_t(1.0, 2.0))), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(2, 1)),                           c_t(boost::math::atanh(s_t(2.0, 1.0))), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(20, -71)),                        c_t(boost::math::atanh(s_t(20, -71))), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(1.0e160, 1.0e160)),               c_t(boost::math::atanh(s_t(1.0e160, 1.0e160))), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(1.0e300, 1.0e160)),               c_t(boost::math::atanh(s_t(1.0e300, 1.0e160))), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(1.0e160, 1.0e300)),               c_t(boost::math::atanh(s_t(1.0e160, 1.0e300))), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(2, 1.0e300)),                     c_t(boost::math::atanh(s_t(2, 1.0e300))), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(1.0e160, 2)),                     c_t(boost::math::atanh(s_t(1.0e160, 2))), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(1.0e-160, 1.0e-160)),             c_t(boost::math::atanh(s_t(1.0e-160, 1.0e-160))), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(1.0e-300, 1.0e-160)),             c_t(boost::math::atanh(s_t(1.0e-300, 1.0e-160))), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(1.0e-160, 1.0e-300)),             c_t(boost::math::atanh(s_t(1.0e-160, 1.0e-300))), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(1.0, 1.0e160)),                   c_t(boost::math::atanh(s_t(1.0, 1.0e160))), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(1.0e-160, 1.0e160)),              c_t(boost::math::atanh(s_t(1.0e-160, 1.0e160))), 2);
  STF_ULP_EQUAL(bs::atanh(c_t(1.0e-160, 1.0e-160)),             c_t(boost::math::atanh(s_t(1.0e-160, 1.0e-160))), 2);
}
