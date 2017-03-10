//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <scalar_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL("Check basic behavior of raw_(frexp)", STF_IEEE_TYPES)
{
  auto p = bs::raw_(bs::frexp)(T(1));
  STF_EQUAL(p.mantissa , T(0.5));
  STF_EQUAL(p.exponent , T(1));
}

STF_CASE_TPL("Check behavior of raw_(frexp) on Valmax", STF_IEEE_TYPES)
{
  auto r = bs::raw_(bs::frexp)(bs::Valmax<T>());

  STF_ULP_EQUAL (r.mantissa, T(1)-bs::Halfeps<T>(), 1);
  STF_EQUAL     (r.exponent, bs::Limitexponent<T>());
  STF_EQUAL     (ldexp(r.mantissa,static_cast<int>(r.exponent)),bs::Valmax<T>());
}
