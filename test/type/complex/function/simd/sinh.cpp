//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/sinh.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/minf.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex sinh complex<pack<T>>", STF_IEEE_TYPES)
{
    using p_t = bs::pack<T,4>;
    using cp_t = bs::complex<p_t>;
    p_t r(T(0), T(-3), T(1), T(2)),  i(2, 4, 1, 0);
    p_t r1(0.0, 6.5481200409110016477668110188353, 0.63496391478473610825508220299151, 3.6268604078470187676682139828013),
      i1(0.90929742682568169539601986591174, -7.6192317203214102084871357368043, 1.2984575814159772948260423658078, 0.0);
    cp_t c1(r, i),  c2(r1, i1);
    STF_ULP_EQUAL(bs::sinh(c1), c2, 1.0);
}
