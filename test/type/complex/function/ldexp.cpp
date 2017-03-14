//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/ldexp.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/meta/as_logical.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex ldexp on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(0,4), r1(4,0), r2(bs::Inf<T>(),3);

  STF_EQUAL(bs::ldexp(r0, 2), r0*4);
  STF_EQUAL(bs::ldexp(r0, -1), r0*T(0.5));
  STF_EQUAL(bs::ldexp(r1, 2), r1*4);
  STF_EQUAL(bs::ldexp(r1, -1), r1*T(0.5));
  STF_EQUAL(bs::ldexp(r2, 2), r2*4);
  STF_EQUAL(bs::ldexp(r2, -1), r2*T(0.5));
}

STF_CASE_TPL( "Complex ldexp complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;

  p_t r{4, 3, -1, 0};
  p_t i{0, 3, 0, -2 };

  bs::complex<p_t> r0{r,i};
  STF_EQUAL(bs::ldexp(r0, 2) , r0*4);
  STF_EQUAL(bs::ldexp(r0,-1) , r0*T(0.5));
}
