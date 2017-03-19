//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/unary_minus.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex unary_minus complex<pack<T>>", STF_IEEE_TYPES)
{
   using p_t = bs::pack<T,4>;
  p_t r0(0,9,-16,-1);
  p_t i0(2,4,-16, 6);
  STF_EQUAL( -bs::complex<p_t>(r0, i0), bs::complex<p_t>(-r0,-i0));

}

