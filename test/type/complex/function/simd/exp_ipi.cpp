//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/exp_ipi.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/exp_1.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/pi.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( " exp_ipi complex<pack<T>>", STF_IEEE_TYPES)
{
    using p_t = bs::pack<T,4>;
    using cp_t = bs::complex<p_t>;
    p_t r(T(0), T(3), T(-1), T(0.5)),  i(2, 4, 0, 1);
    p_t r1( 0.00186744273170798881443021293483, -0.00000348734235620899549177526626521, -1.0, 0.0),
      i1(0.0, 0.0, 0.0, 0.0432139182637722497744177371717);
    cp_t c1(r, i),  c2(r1, i1);
    STF_ULP_EQUAL(bs::exp_ipi(c1), c2, 03.0);
}


STF_CASE_TPL( " exp_ipi on T", STF_IEEE_TYPES)
{

  STF_ULP_EQUAL( bs::exp_ipi(T(1)), bs::complex<T>(-1, 0), 0.75);
  STF_ULP_EQUAL( bs::exp_ipi(T(0.5)), bs::complex<T>(0, 1), 0.75);
  STF_ULP_EQUAL( bs::exp_ipi(bs::Inf<T>()),  bs::complex<T>(bs::Nan<T>(), bs::Nan<T>()), 0.5);
}

