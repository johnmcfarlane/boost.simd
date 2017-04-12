//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/plus.hpp>
#include <scalar_test.hpp>

#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>

STF_CASE_TPL( "Check plus behavior with floating", STF_IEEE_TYPES )
{
  namespace bs = boost::simd;
  using bs::plus;

#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL     (plus(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL     (plus(bs::Minf<T>(), bs::Minf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(plus(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
#endif

  STF_EQUAL(plus(T(1),T(0)), T(1));
  STF_EQUAL(plus(T(1),T(1)), T(2));
  STF_EQUAL(plus(T(0),T(1)), T(1));
  STF_EQUAL(plus(T(0),T(0)), T(0));
}
