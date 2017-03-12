//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/exp.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/exp_1.hpp>
#include <boost/simd/constant/minf.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex exp on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 0);
  STF_ULP_EQUAL( bs::exp(c1), bs::complex<T>(-0.41614683654714238699756822950076, 0.90929742682568169539601986591174), 0.5);
  STF_ULP_EQUAL( bs::exp(c2), bs::complex<T>(-0.032542999640154784793933107703479, -0.037678977574865854770790450265886), 0.5);
  STF_ULP_EQUAL( bs::exp(c3), bs::complex<T>(bs::Exp_1<T>(), T(0)), 0.5);
}


STF_CASE_TPL( "Complex exp complex<pack<T>>", STF_IEEE_TYPES)
{
    using p_t = bs::pack<T,4>;
    using cp_t = bs::complex<p_t>;
    p_t r(T(0), T(-3), T(1), bs::Minf<T>()),  i(2, 4, 0, 1);
    p_t r1(-0.41614683654714238699756822950076, -0.032542999640154784793933107703479 , 2.7182818284590452353602874713527, 0.0),
      i1(0.90929742682568169539601986591174,  -0.037678977574865854770790450265886, 0.0, 0.0);
    cp_t c1(r, i),  c2(r1, i1);
    STF_ULP_EQUAL(bs::exp(c1), c2, 0.5);
}




