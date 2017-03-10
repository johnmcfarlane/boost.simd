//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/is_eqz.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <boost/simd/meta/as_logical.hpp>

namespace bs = boost::simd;
namespace bsc =  bs::cmplx;

STF_CASE_TPL( "Complex is_eqz on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(0,4), r1(4,0), r2(0, 0), r3(bs::Minf<T>(),0);

  STF_EQUAL(bs::is_eqz(r0), false);
  STF_EQUAL(bs::is_eqz(r1), false);
  STF_EQUAL(bs::is_eqz(r2), true);
  STF_EQUAL(bs::is_eqz(r3), false);
}

STF_CASE_TPL( "Complex is_eqz complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using lp_t  = bs::as_logical_t<p_t>;

  p_t r{4, 3, bs::Inf<T>(), 0};
  p_t i{0, 3, 0 ,0 };

  bs::complex<p_t> r0{r,i};
  STF_EQUAL(bs::is_eqz(r0) , (lp_t{false,false,false,true}));
}
