//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/real.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex real complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;

  p_t r{4, 3, -1, 0};
  p_t i{0, 3, 0 ,-2};

  bs::complex<p_t> r0{r,i};

  STF_EQUAL(bs::real(r0) , r0.real);
}
