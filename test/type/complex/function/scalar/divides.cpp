//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/abs.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Divides with complex<T>/complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(4,0), r1(0,4), r2(2,2);

  STF_EQUAL(r0 / r0, bs::complex<T>(1, 0));
  STF_EQUAL(r1 / r1, bs::complex<T>(1, 0));
  STF_EQUAL(r2 / r2, bs::complex<T>(1, 0));
  STF_EQUAL(r0 / r1, bs::complex<T>(0, -1));
  STF_EQUAL(r0 / r2, bs::complex<T>(1, -1));
  STF_EQUAL(r1 / r2, bs::complex<T>(1, 1));
}

STF_CASE_TPL( "Divides with complex<T>/T", STF_IEEE_TYPES)
{
  bs::complex<T> r0(6,0), r1(0,2), r2(2,2);

  STF_EQUAL(r0 / 3 , bs::complex<T>(2,0));
  STF_EQUAL(3  / r0, bs::complex<T>(0.5,0));
  STF_EQUAL(r1 / 3 , bs::complex<T>(0, 2.0/3.0));
  STF_EQUAL(3  / r1, bs::complex<T>(0, -1.5));
  STF_EQUAL(r2 / 2 , bs::complex<T>(1, 1));
  STF_EQUAL(4  / r2, bs::complex<T>(1, -1));
}
