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

STF_CASE_TPL( "Equality comparison complex<T>/pack<T>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T>;
  using pl_t = bs::pack<bs::logical<T>>;

  bs::complex<T>  x(69,0);
  p_t             r0(69), r1(37);

  STF_EQUAL( (x == r0), (pl_t{true}) );
  STF_EQUAL( (x == r1), (pl_t{false}) );
}

STF_CASE_TPL( "Equality comparison to complex<T>/T", STF_IEEE_TYPES)
{
  bs::complex<T> x(4);

  STF_EQUAL((x == 4), true );
  STF_EQUAL((4 == x), true );
  STF_EQUAL((x == 3), false);
  STF_EQUAL((7 == x), false);
}

STF_CASE_TPL( "Equality comparison to complex<pack<T>>/complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pl_t = bs::pack<bs::logical<T>,4>;

  p_t r{4,-3, 0,7};
  p_t i{2, 9, 0,8};

  bs::complex<p_t> x{r,i}, r0{r,i}, r1{r,r}, r2{i,i}, r3{i,r};

  STF_EQUAL( (x == r0), (pl_t{true}) );
  STF_EQUAL( (x == r1), (pl_t{false,false,true,false}) );
  STF_EQUAL( (x == r2), (pl_t{false,false,true,false}) );
  STF_EQUAL( (x == r3), (pl_t{false,false,true,false}) );
}

STF_CASE_TPL( "Equality comparison to complex<pack<T>>/pack<T>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pl_t = bs::pack<bs::logical<T>,4>;

  p_t r{4,-3, 0,7};
  p_t q{2, 9, 0,8};
  p_t s{2, 0, 9,8};

  bs::complex<p_t> x{r,p_t(0)},y(r,q);

  STF_EQUAL( (x == r), (pl_t{true}) );
  STF_EQUAL( (r == x), (pl_t{true}) );
  STF_EQUAL( (x == q), (pl_t{false,false,true ,false}) );
  STF_EQUAL( (q == x), (pl_t{false,false,true ,false}) );
  STF_EQUAL( (y == s), (pl_t{false}) );
  STF_EQUAL( (s == y), (pl_t{false}) );
}

STF_CASE_TPL( "Equality comparison to complex<pack<T>>/T", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T>;
  using pl_t = bs::pack<bs::logical<T>>;

  bs::complex<p_t> x{p_t{4},0};

  STF_EQUAL( (x == 4), (pl_t{true}) );
  STF_EQUAL( (4 == x), (pl_t{true}) );
  STF_EQUAL( (x == 0), (pl_t{false}) );
  STF_EQUAL( (0 == x), (pl_t{false}) );
}
