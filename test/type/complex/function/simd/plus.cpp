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

STF_CASE_TPL( "Addition with complex<T>/pack<T>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using c_t  = bs::complex<T>;
  using pc_t = bs::complex<p_t>;

  c_t r0(4,0), r1(0,2), r2(2,2);
  p_t v{3,-2,0,1};

  STF_EQUAL(r0 + v , (pc_t{ p_t(7, 2,4,5), p_t(0,0,0,0) }));
  STF_EQUAL(v  + r0, (pc_t{ p_t(7, 2,4,5), p_t(0,0,0,0) }));
  STF_EQUAL(r1 + v , (pc_t{ p_t(3,-2,0,1), p_t(2,2,2,2) }));
  STF_EQUAL(v  + r1, (pc_t{ p_t(3,-2,0,1), p_t(2,2,2,2) }));
  STF_EQUAL(r2 + v , (pc_t{ p_t(5, 0,2,3), p_t(2,2,2,2) }));
  STF_EQUAL(v  + r2, (pc_t{ p_t(5, 0,2,3), p_t(2,2,2,2) }));
}

STF_CASE_TPL( "Addition with to complex<pack<T>>/complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pc_t = bs::complex<p_t>;

  p_t   r{3,-2,0,1}, i{0,5,-2,-5};
  pc_t  r0(r,i), r1(r,0), r2(0,i);

  STF_EQUAL(r1 + r2, r0);
}

STF_CASE_TPL( "Addition with to complex<pack<T>>/pack<T>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pc_t = bs::complex<p_t>;

  p_t   r{3,-2,0,1}, i{0,5,-2,-5};
  pc_t  r0(r,i), r1(r,0), r2(0,i);

  STF_EQUAL(r1 + r  , pc_t(r+r,0));
  STF_EQUAL(r  + r1 , pc_t(r+r,0));
  STF_EQUAL(r2 + r  , r0);
  STF_EQUAL(r  + r2 , r0);
}

STF_CASE_TPL( "Addition with to complex<pack<T>>/complex<T>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using c_t  = bs::complex<T>;
  using pc_t = bs::complex<p_t>;

  c_t   i(0,3);
  p_t   rr{0,5,-2,-5};
  pc_t  r(rr,0), res(rr,3);

  STF_EQUAL(r + i, res);
}

STF_CASE_TPL( "Addition with to complex<pack<T>>/T", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pc_t = bs::complex<p_t>;

  p_t   r{3}, i{0,5,-2,-5};
  pc_t  r0(r,i), r1(0,i);

  STF_EQUAL(r1 + 3  , r0);
  STF_EQUAL(3 + r1 , r0);
}
