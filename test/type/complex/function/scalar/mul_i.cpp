//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/mul_i.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>


namespace bs = boost::simd;

STF_CASE_TPL( "Complex mul_i on complex<T>", STF_IEEE_TYPES)
{

  bs::complex<T> c1(0, 4);
  STF_EQUAL( bs::mul_i(c1), bs::complex<T>(-4, 0));

}

STF_CASE_TPL( "Complex mul_i on T", STF_IEEE_TYPES)
{

  T c1(4);
  STF_EQUAL( bs::mul_i(c1), bs::complex<T>(0, 4));

}


