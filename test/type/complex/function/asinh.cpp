//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/asinh.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex asinh on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::asinh(c1), bs::complex<T>(-1.316957896924816708625046347308, 1.5707963267948966192313216916398), 0.5);
  STF_ULP_EQUAL( bs::asinh(c2), bs::complex<T>(- 2.2999140408792696499557896306632, 0.91761685335147865575986274867017), 1.5);
  STF_ULP_EQUAL( bs::asinh(c3), bs::complex<T>(1.0612750619050356520330189162136, 0.66623943249251525510400489597779), 0.5);
}


STF_CASE_TPL( "Complex asinh complex<pack<T>>", STF_IEEE_TYPES)
{
    using p_t = bs::pack<T,4>;
    using cp_t = bs::complex<p_t>;
    p_t r(T(0), T(-3), T(1), T(2)),  i(2, 4, 1, 0);
    p_t r1( -1.316957896924816708625046347308, -2.2999140408792696499557896306632, 1.0612750619050356520330189162136, 1.4436354751788103424932767402731),
      i1( 1.5707963267948966192313216916398, 0.91761685335147865575986274867017, 0.66623943249251525510400489597779, 0);
    cp_t c1(r, i),  c2(r1, i1);
    STF_ULP_EQUAL(bs::asinh(c1), c2, 1.5);
}

