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
/*
STF_CASE_TPL( "Complex sqrt on complex<T>", STF_IEEE_TYPES)
{

}
*/
STF_CASE_TPL( "Complex sqrt on T", STF_IEEE_TYPES)
{
  T r0(0), r1(9), r2(-16);

  STF_EQUAL( bs::cmplx::sqrt(r0), bs::complex<T>(0,0));
  STF_EQUAL( bs::cmplx::sqrt(r1), bs::complex<T>(3,0));
  STF_EQUAL( bs::cmplx::sqrt(r2), bs::complex<T>(0,4));
}

/*
STF_CASE_TPL( "Complex sqrt complex<pack<T>>", STF_IEEE_TYPES)
{

}
*/

STF_CASE_TPL( "Complex sqrt on pack<T>", STF_IEEE_TYPES)
{
  using p_t = bs::pack<T,4>;
  p_t r0(0,9,-16,-1);

  STF_EQUAL( bs::cmplx::sqrt(r0), bs::complex<p_t>(p_t(0,3,0,0),p_t(0,0,4,1)));
}

