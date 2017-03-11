//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/real.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex real on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(0,4), r1(4,0), r2(3,3), r3(-1,0), r4(0,-1), r5(-2,-2);

  STF_EQUAL(bs::real(r0), r0.real);
  STF_EQUAL(bs::real(r1), r1.real);
  STF_EQUAL(bs::real(r2), r2.real);
  STF_EQUAL(bs::real(r3), r3.real);
  STF_EQUAL(bs::real(r4), r4.real);
  STF_EQUAL(bs::real(r5), r5.real);
}

STF_CASE_TPL( "Complex real complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;

  p_t r{4, 3, -1, 0};
  p_t i{0, 3, 0 ,-2};

  bs::complex<p_t> r0{r,i};

  STF_EQUAL(bs::real(r0) , r0.real);
}
