//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/sqr.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex sqr on complex<T>", STF_IEEE_TYPES)
{

  bs::complex<T> c1(0, 4);
  STF_EQUAL( bs::sqr(c1), bs::complex<T>(-16, 0));

}



STF_CASE_TPL( "Complex sqr complex<pack<T>>", STF_IEEE_TYPES)
{
   using p_t = bs::pack<T,4>;
  p_t r0(0,9,-16,-1);
  p_t i0(2,4,-16, 6);
  p_t r02(-4,    65,     0,   -35);
  p_t i02(0,    72,   512,   -12);

  STF_EQUAL( bs::sqr(bs::complex<p_t>(r0, i0)), bs::complex<p_t>(r02,i02));

}

