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

STF_CASE_TPL( "Complex sinh on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::sinh(c1), bs::complex<T>(0.0, 0.90929742682568169539601986591174), 0.5);
  STF_ULP_EQUAL( bs::sinh(c2), bs::complex<T>(6.5481200409110016477668110188353, -7.6192317203214102084871357368043), 0.5);
  STF_ULP_EQUAL( bs::sinh(c3), bs::complex<T>( 0.63496391478473610825508220299151, 1.2984575814159772948260423658078), 1.0);
}


