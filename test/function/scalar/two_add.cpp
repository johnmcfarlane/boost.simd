//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/two_add.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/eps.hpp>
#include <scalar_test.hpp>

STF_CASE_TPL(" two_add", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::two_add;

  T inf_    = bs::Inf<T>();
  T zero_   = T(0);
  T one_    = T(1);
  T half_   = T(0.5);
  T eps_    = bs::Eps<T>();
  T eps_2_  = eps_/T(2);

  auto p = two_add(inf_,zero_);
  STF_EQUAL(p.low, inf_);
  STF_EQUAL(p.high, zero_);

  p = two_add(zero_, inf_);
  STF_EQUAL(p.low, inf_);
  STF_EQUAL(p.high, zero_);

  p = two_add(half_+ eps_2_, half_);
  STF_EQUAL(p.low, one_);
  STF_EQUAL(p.high, eps_2_);

  p = two_add(half_, half_+ eps_2_);
  STF_EQUAL(p.low, one_);
  STF_EQUAL(p.high, eps_2_);
}
