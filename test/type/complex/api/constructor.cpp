//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "simd::complex constructor from scalar (real)", STF_IEEE_TYPES)
{
  bs::complex<T> x(42);

  STF_EQUAL(x.real, T(42));
  STF_EQUAL(x.imag, T(0));
}

STF_CASE_TPL( "simd::complex constructor from SIMD (real)", STF_IEEE_TYPES)
{
  auto r = bs::enumerate<bs::pack<T>>(1,2);

  bs::complex<bs::pack<T>> x(r);

  STF_EQUAL(x.real, r);
  STF_EQUAL(x.imag, bs::pack<T>(0));
}

STF_CASE_TPL( "simd::complex constructor from scalar (real,imag) pair", STF_IEEE_TYPES)
{
  bs::complex<T> x(13, 37);

  STF_EQUAL(x.real, T(13));
  STF_EQUAL(x.imag, T(37));
}

STF_CASE_TPL( "simd::complex constructor from SIMD (real,imag) pair", STF_IEEE_TYPES)
{
  auto r = bs::enumerate<bs::pack<T>>(2,-2);
  auto i = bs::enumerate<bs::pack<T>>(1,2);

  bs::complex<bs::pack<T>> x( r, i);

  STF_EQUAL(x.real, r);
  STF_EQUAL(x.imag, i);
}
