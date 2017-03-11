//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/real.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>

STF_CASE_TPL (" real real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::real;

  using r_t = decltype(real(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(real(bs::Inf<T>()), bs::Inf<r_t>());
  STF_EQUAL(real(bs::Minf<T>()), bs::Minf<r_t>());
  STF_IEEE_EQUAL(real(bs::Nan<T>()), bs::Nan<r_t>());
  STF_EQUAL(real(bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(real(bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_

