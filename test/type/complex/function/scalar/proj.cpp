//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/proj.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex proj on complex<T>", STF_IEEE_TYPES)
{

  bs::complex<T> c1(0, 4), c2(bs::Inf<T>(), T(1.0)), c3(T(2.0),  bs::Minf<T>()), c4(T(2), bs::Nan<T>()), c5(bs::Minf<T>(), T(-1.0)) ;
  bs::complex<T> r1(0, 4), r2(bs::Inf<T>(), T(0.0)), r3(bs::Inf<T>(), T(-0.0)) , r4(T(2), bs::Nan<T>()), r5(bs::Inf <T>(), T(-0.0)) ;
  STF_IEEE_EQUAL( bs::proj(c1), r1);
  STF_IEEE_EQUAL( bs::proj(c2), r2);
  STF_IEEE_EQUAL( bs::proj(c3), r3);
  STF_IEEE_EQUAL( bs::proj(c4), r4);
  STF_IEEE_EQUAL( bs::proj(c5), r5);
}



