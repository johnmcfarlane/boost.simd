//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/is_finite.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/meta/as_logical.hpp>

namespace bs = boost::simd;
namespace bsc =  bs::cmplx;

STF_CASE_TPL( "Complex is_finite on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(0,4), r1(4,0), r2(bs::Inf<T>(),3), r3(-1,bs::Inf<T>())
    , r4(bs::Minf<T>(),-1), r5(-2,bs::Nan<T>());

  STF_EQUAL(bs::is_finite(r0), true);
  STF_EQUAL(bs::is_finite(r1), true);
  STF_EQUAL(bs::is_finite(r2), false);
  STF_EQUAL(bs::is_finite(r3), false);
  STF_EQUAL(bs::is_finite(r4), false);
  STF_EQUAL(bs::is_finite(r5), false);
}

STF_CASE_TPL( "Complex is_finite complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using lp_t  = bs::as_logical_t<p_t>;

  p_t r{4, 3, bs::Inf<T>(), 0};
  p_t i{0, 3, 0 ,bs::Nan<T>() };

  bs::complex<p_t> r0{r,i};
  STF_EQUAL(bs::is_finite(r0) , (lp_t{true,true,false,false}));
}
