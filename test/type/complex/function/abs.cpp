//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/abs.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex abs on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(0,4), r1(4,0), r2(3,3), r3(-1,0), r4(0,-1), r5(-2,-2);

  STF_EQUAL(r0.modulus(), T(16));
  STF_EQUAL(r1.modulus(), T(16));
  STF_EQUAL(r2.modulus(), T(18));
  STF_EQUAL(r3.modulus(), T(1));
  STF_EQUAL(r4.modulus(), T(1));
  STF_EQUAL(r5.modulus(), T(8));

  STF_EQUAL(bs::abs(r0), T(16));
  STF_EQUAL(bs::abs(r1), T(16));
  STF_EQUAL(bs::abs(r2), T(18));
  STF_EQUAL(bs::abs(r3), T(1));
  STF_EQUAL(bs::abs(r4), T(1));
  STF_EQUAL(bs::abs(r5), T(8));
}

STF_CASE_TPL( "Complex abs complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;

  p_t r{4, 3, -1, 0};
  p_t i{0, 3, 0 ,-2};

  bs::complex<p_t> r0{r,i};

  STF_EQUAL(r0.modulus(), (p_t{16,18,1,4}));
  STF_EQUAL(bs::abs(r0) , (p_t{16,18,1,4}));
}
