//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/atan.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex atan on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1), c4(2, 0);
  STF_ULP_EQUAL( bs::atan(c1), bs::complex<T>(1.5707963267948966192313216916398, 0.54930614433405484569762261846126  ), 0.5);
  STF_ULP_EQUAL( bs::atan(c2), bs::complex<T>(- 1.4483069952314645421452804510341, 0.15899719167999917436476103600702), 1.5);
  STF_ULP_EQUAL( bs::atan(c3), bs::complex<T>( 1.0172219678978513677227889615505, 0.40235947810852509365018983330655 ), 0.5);
  STF_ULP_EQUAL( bs::atan(c4), bs::complex<T>( 1.1071487177940905030170654601785, 0), 0.5);
}


STF_CASE_TPL( "Complex atan complex<pack<T>>", STF_IEEE_TYPES)
{
    using p_t = bs::pack<T,4>;
    using cp_t = bs::complex<p_t>;
    p_t r(T(0), T(-3), T(1), T(2)),  i(2, 4, 1, 0);
    p_t r1( 1.5707963267948966192313216916398, -1.4483069952314645421452804510341, 1.0172219678978513677227889615505, 1.1071487177940905030170654601785),
      i1( 0.54930614433405484569762261846126, 0.15899719167999917436476103600702, 0.40235947810852509365018983330655, 0);
    cp_t c1(r, i),  c2(r1, i1);
    STF_ULP_EQUAL(bs::atan(c1), c2, 1.5);
}

