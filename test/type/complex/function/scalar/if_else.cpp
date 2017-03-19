//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/if_else.hpp>
#include <boost/simd/type/complex/function/sqr_abs.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>


namespace bs = boost::simd;

STF_CASE_TPL( "Addition with complex<T>/complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(4,0), r1(0,2), r2(2,2);

  STF_EQUAL(bs::if_else(bs::sqr_abs(r0) < bs::sqr_abs(r1), r0, r1), r1);
}




