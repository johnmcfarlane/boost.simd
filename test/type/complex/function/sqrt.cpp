//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/sqrt.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex sqrt on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(0,4), r1(4,0), r2(3,3), r3(-1,0), r4(0,-1), r5(-2,-2);

  STF_EQUAL(bs::cmplx::sqrt(r0), bs::complex<T>(0,2));
  STF_EQUAL(bs::cmplx::sqrt(r1), bs::complex<T>(2,0));
}
/*
STF_CASE_TPL( "Complex sqrt on T", STF_IEEE_TYPES)
{
  bs::complex<T> x(4,2), r0(4,2), r1(6,2), r2(4,6), r3(7,9);

  STF_EQUAL((x == r0), true);
  STF_EQUAL((x == r1), false);
  STF_EQUAL((x == r2), false);
  STF_EQUAL((x == r3), false);
}

STF_CASE_TPL( "Complex sqrt complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pl_t = bs::pack<bs::logical<T>,4>;

  p_t r{4,-3, 0,7};
  p_t i{2, 9, 0,8};

  bs::complex<p_t> x{r,i}, r0{r,i}, r1{r,r}, r2{i,i}, r3{i,r};

  STF_EQUAL( (x == r0), (pl_t{true}) );
  STF_EQUAL( (x == r1), (pl_t{false,false,true,false}) );
  STF_EQUAL( (x == r2), (pl_t{false,false,true,false}) );
  STF_EQUAL( (x == r3), (pl_t{false,false,true,false}) );
}

STF_CASE_TPL( "Complex sqrt pack<T>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pl_t = bs::pack<bs::logical<T>,4>;

  p_t r{4,-3, 0,7};
  p_t i{2, 9, 0,8};

  bs::complex<p_t> x{r,i}, r0{r,i}, r1{r,r}, r2{i,i}, r3{i,r};

  STF_EQUAL( (x == r0), (pl_t{true}) );
  STF_EQUAL( (x == r1), (pl_t{false,false,true,false}) );
  STF_EQUAL( (x == r2), (pl_t{false,false,true,false}) );
  STF_EQUAL( (x == r3), (pl_t{false,false,true,false}) );
}
*/
