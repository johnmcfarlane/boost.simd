//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Multiplies with complex<T>/complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(4,0), r1(0,2), r2(2,2);

  STF_EQUAL(r0 * r0, bs::complex<T>(16,0));
  STF_EQUAL(r1 * r1, bs::complex<T>(-4,0));
  STF_EQUAL(r2 * r2, bs::complex<T>(0, 8));
  STF_EQUAL(r0 * r1, bs::complex<T>(0, 8));
  STF_EQUAL(r0 * r2, bs::complex<T>(8, 8));
  STF_EQUAL(r1 * r2, bs::complex<T>(-4, 4));
}

STF_CASE_TPL( "Multiplies with complex<T>/T", STF_IEEE_TYPES)
{
  bs::complex<T> r0(4,0), r1(0,2), r2(2,2);

  STF_EQUAL(r0 * 3 , bs::complex<T>(12,0));
  STF_EQUAL(3  * r0, bs::complex<T>(12,0));
  STF_EQUAL(r1 * 3 , bs::complex<T>(0, 6));
  STF_EQUAL(3  * r1, bs::complex<T>(0, 6));
  STF_EQUAL(r2 * 7 , bs::complex<T>(14, 14));
  STF_EQUAL(7  * r2, bs::complex<T>(14, 14));
}

STF_CASE_TPL( "Multiplies with complex<T>/pack<T>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using c_t  = bs::complex<T>;
  using pc_t = bs::complex<p_t>;

  c_t r0(4,0), r1(0,2), r2(4,2);
  p_t v{3,-2,0,1};

  STF_EQUAL(r0 * v , (pc_t{ p_t(12, -8, 0, 4), p_t(0,0,0,0) }));
  STF_EQUAL(v  * r0, (pc_t{ p_t(12, -8, 0, 4), p_t(0,0,0,0) }));
  STF_EQUAL(r1 * v , (pc_t{ p_t(0), p_t(6, -4, 0, 2) }));
  STF_EQUAL(v  * r1, (pc_t{ p_t(0), p_t(6, -4, 0, 2) }));
  STF_EQUAL(r2 * v , (pc_t{ p_t(12, -8, 0, 4), p_t(6, -4, 0, 2) }));
  STF_EQUAL(v  * r2, (pc_t{ p_t(12, -8, 0, 4), p_t(6, -4, 0, 2) }));
}


