//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/asin.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/sin.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;


STF_CASE_TPL( "Complex asin complex<pack<T>>", STF_IEEE_TYPES)
{
    using p_t = bs::pack<T,4>;
    using cp_t = bs::complex<p_t>;
    p_t r(T(0), T(-3), T(1), T(2)),  i(2, 4, 1, 0);
    p_t r1(0, -0.63398386563917671631879711506414, 0.66623943249251525510400489597779, 1.5707963267948966192313216916398),
      i1(1.4436354751788103424932767402731, 2.3055090312434769420418359381334, 1.0612750619050356520330189162136, 1.316957896924816708625046347308);
    cp_t c1(r, i),  c2(r1, i1);
   STF_ULP_EQUAL(bs::asin(c1), c2, 1.0);
}

