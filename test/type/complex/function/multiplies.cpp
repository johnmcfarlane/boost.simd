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

STF_CASE_TPL( "Multiplies with to complex<pack<T>>/complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pc_t = bs::complex<p_t>;

  p_t   r1(1,2,3,4), r2(4, 3, 2, 1), r3(5,6,7,8);
  pc_t  c0(r1, r3), c1(r2, r1), c2(p_t(-1,   -6,  -15,  -28), p_t(21,   22,   23,   24));

  STF_EQUAL(c0 * c1, c2);
}

STF_CASE_TPL( "Multiplies with to complex<pack<T>>/pack<T>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pc_t = bs::complex<p_t>;

  p_t   r1(1,2,3,4), r2(4, 3, 2, 1), r3(5,6,7,8);
  pc_t  c0(r1, r3), c3(p_t(4,   6,   6,   4), p_t(20,   18,   14,    8));

  STF_EQUAL(c0*r2 , c3);

}

STF_CASE_TPL( "Multiplies with to complex<pack<T>>/complex<T>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using c_t  = bs::complex<T>;
  using pc_t = bs::complex<p_t>;

  c_t   i(1,3);
  p_t   rr{0,5,-2,-5};
  pc_t  r(p_t( 0,   5,  -2,  -5), p_t(0,   15,   -6,  -15));

  STF_EQUAL(rr * i, r);
}

STF_CASE_TPL( "Multiplies with to complex<pack<T>>/T", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pc_t = bs::complex<p_t>;

  p_t   r(1,2,3,4), i(4, 3, 2, 1);
  p_t   r3(3, 6, 9, 12), i3(12, 9, 6, 3);
  pc_t  c0(r,i), c1(r3, i3);

  STF_EQUAL(c0 * 3  , c1);
  STF_EQUAL(3 * c0 , c1);
}
