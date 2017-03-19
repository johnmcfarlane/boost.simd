//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/mul_mi.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>


namespace bs = boost::simd;

STF_CASE_TPL( "Complex mul_mi on complex<T>", STF_IEEE_TYPES)
{

  bs::complex<T> c1(0, 4);
  STF_EQUAL( bs::mul_mi(c1), bs::complex<T>(4, 0));

}

STF_CASE_TPL( "Complex mul_mi on T", STF_IEEE_TYPES)
{

  T c1(4);
  STF_EQUAL( bs::mul_mi(c1), bs::complex<T>(0, -4));

}


