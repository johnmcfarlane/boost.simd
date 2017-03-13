//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/sin.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex sin on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::sin(c1), bs::complex<T>(0.0,  3.6268604078470187676682139828013), 0.5);
  STF_ULP_EQUAL( bs::sin(c2), bs::complex<T>( -3.8537380379193773216175289404637, -27.016813258003934488097543754992), 0.5);
  STF_ULP_EQUAL( bs::sin(c3), bs::complex<T>(1.2984575814159772948260423658078, 0.63496391478473610825508220299151 ), 1.0);
}


STF_CASE_TPL( "Complex sin complex<pack<T>>", STF_IEEE_TYPES)
{
    using p_t = bs::pack<T,4>;
    using cp_t = bs::complex<p_t>;
    p_t r(T(0), T(-3), T(1), T(2)),  i(2, 4, 1, 0);
    p_t r1( 0, -3.8537380379193773216175289404637, 1.2984575814159772948260423658078, 0.90929742682568169539601986591174),
      i1(  3.6268604078470187676682139828013, -27.016813258003934488097543754992, 0.63496391478473610825508220299151, 0);
    cp_t c1(r, i),  c2(r1, i1);
    STF_ULP_EQUAL(bs::sin(c1), c2, 1.0);
}

