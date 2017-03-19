//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/is_nan.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/meta/as_logical.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex is_nan on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(0,4), r1(bs::Nan<T>(),0), r2(0, bs::Nan<T>()), r3(bs::Minf<T>(),0), r4(bs::Nan<T>(), bs::Nan<T>());

  STF_EQUAL(bs::is_nan(r0), false);
  STF_EQUAL(bs::is_nan(r1), true);
  STF_EQUAL(bs::is_nan(r2), true);
  STF_EQUAL(bs::is_nan(r3), false);
  STF_EQUAL(bs::is_nan(r4), true);
}


