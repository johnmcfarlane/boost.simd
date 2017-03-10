//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/ifrexp.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <scalar_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

STF_CASE_TPL("Check basic behavior of ifrexp", STF_IEEE_TYPES)
{
  auto p = bs::ifrexp(T(1));
  STF_EQUAL(p.mantissa  , T(0.5));
  STF_EQUAL(p.exponent , T(1));
}

STF_CASE_TPL("Check behavior of ifrexp on Zero", STF_IEEE_TYPES)
{
  auto r = bs::ifrexp(T(0));

  STF_EQUAL (r.mantissa , T(0));
  STF_EQUAL (r.exponent, T(0));
  STF_EQUAL (ldexp(r.mantissa,static_cast<int>(r.exponent)), T(0));
}

STF_CASE_TPL("Check behavior of ifrexp on Valmax", STF_IEEE_TYPES)
{
  auto r = bs::ifrexp(bs::Valmax<T>());

  STF_ULP_EQUAL (r.mantissa , T(1)-bs::Halfeps<T>(), 1);
  STF_EQUAL     (r.exponent, bs::Limitexponent<T>());
  STF_EQUAL     (ldexp(r.mantissa,static_cast<int>(r.exponent)),bs::Valmax<T>());
}
