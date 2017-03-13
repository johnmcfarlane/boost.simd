//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/acosh.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex acosh on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::cmplx::acosh(c1), bs::complex<T>(1.4436354751788103424932767402731, 1.5707963267948966192313216916398), 0.5);
  STF_ULP_EQUAL( bs::cmplx::acosh(c2), bs::complex<T>(2.3055090312434769420418359381334, 2.2047801924340733355501188067039), 0.5);
  STF_ULP_EQUAL( bs::cmplx::acosh(c3), bs::complex<T>(1.0612750619050356520330189162136, 0.90455689430238136412731679566196), 0.5);
}


STF_CASE_TPL( "Complex acosh complex<pack<T>>", STF_IEEE_TYPES)
{
    using p_t = bs::pack<T,4>;
    using cp_t = bs::complex<p_t>;
    p_t r(T(0), T(-3), T(1), T(2)),  i(2, 4, 1, 0);
    p_t r1(1.4436354751788103424932767402731, 2.3055090312434769420418359381334, 1.0612750619050356520330189162136, 1.316957896924816708625046347308),
      i1( 1.5707963267948966192313216916398, 2.2047801924340733355501188067039, 0.90455689430238136412731679566196, 0);
    cp_t c1(r, i),  c2(r1, i1);
    STF_ULP_EQUAL(bs::cmplx::acosh(c1), c2, 1.0);
}

