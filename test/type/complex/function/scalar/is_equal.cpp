//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Equality comparison complex<T>/complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> x(4,2), r0(4,2), r1(6,2), r2(4,6), r3(7,9);

  STF_EQUAL((x == r0), true);
  STF_EQUAL((x == r1), false);
  STF_EQUAL((x == r2), false);
  STF_EQUAL((x == r3), false);
}

