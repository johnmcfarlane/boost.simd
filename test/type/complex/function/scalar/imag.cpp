//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/imag.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex imag on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(0,4), r1(4,0), r2(3,3), r3(-1,0), r4(0,-1), r5(-2,-2);

  STF_EQUAL(bs::imag(r0), r0.imag);
  STF_EQUAL(bs::imag(r1), r1.imag);
  STF_EQUAL(bs::imag(r2), r2.imag);
  STF_EQUAL(bs::imag(r3), r3.imag);
  STF_EQUAL(bs::imag(r4), r4.imag);
  STF_EQUAL(bs::imag(r5), r5.imag);
}

