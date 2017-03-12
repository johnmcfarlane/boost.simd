//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/exp_i.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/exp_1.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/pi.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( " exp_i on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(2, 0), c2(4, 3), c3(0, -1);
  STF_ULP_EQUAL( bs::exp_i(c1), bs::complex<T>(-0.41614683654714238699756822950076, 0.90929742682568169539601986591174), 0.5);
  STF_ULP_EQUAL( bs::exp_i(c2), bs::complex<T>(-0.032542999640154784793933107703479, -0.037678977574865854770790450265886), 0.5);
  STF_ULP_EQUAL( bs::exp_i(c3), bs::complex<T>(bs::Exp_1<T>(), T(0)), 0.5);
}


STF_CASE_TPL( " exp_i complex<pack<T>>", STF_IEEE_TYPES)
{
    using p_t = bs::pack<T,4>;
    using cp_t = bs::complex<p_t>;
    p_t i(T(0), T(3), T(-1), bs::Inf<T>()),  r(2, 4, 0, 1);
    p_t r1(-0.41614683654714238699756822950076, -0.032542999640154784793933107703479 , 2.7182818284590452353602874713527, 0.0),
      i1(0.90929742682568169539601986591174,  -0.037678977574865854770790450265886, 0.0, 0.0);
    cp_t c1(r, i),  c2(r1, i1);
    STF_ULP_EQUAL(bs::exp_i(c1), c2, 0.5);
}


STF_CASE_TPL( " exp_i on T", STF_IEEE_TYPES)
{

  STF_ULP_EQUAL( bs::exp_i(bs::Pi<T>()), bs::complex<T>(-1, 0), 0.75);
  STF_ULP_EQUAL( bs::exp_i(bs::Pi<T>()/2), bs::complex<T>(0, 1), 0.75);
  STF_ULP_EQUAL( bs::exp_i(bs::Inf<T>()),  bs::complex<T>(bs::Nan<T>(), bs::Nan<T>()), 0.5);
}


