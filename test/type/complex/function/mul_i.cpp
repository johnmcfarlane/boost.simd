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


STF_CASE_TPL( "Complex mul_i complex<pack<T>>", STF_IEEE_TYPES)
{
   using p_t = bs::pack<T,4>;
   using cp_t = bs::complex<p_t>;
   p_t r0(0,9,-16,-1);
   p_t i0(2,4,-16, 6);
   cp_t a(r0, i0);
   cp_t b(-i0, r0);
   STF_EQUAL( bs::mul_i(a), b);

}

STF_CASE_TPL( "Complex mul_i pack<T>", STF_IEEE_TYPES)
{
  using p_t = bs::pack<T,4>;
  p_t r0(0,9,-16,-1);
  STF_EQUAL( bs::mul_i(r0), bs::complex<p_t>(0, r0));

}
