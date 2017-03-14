//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/sqr_abs.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include <complex>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex sqr_abs on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(0,4), r1(4,0), r2(3,3), r3(-1,0), r4(0,-1), r5(-2,-2);

  STF_EQUAL(bs::sqr_abs(r0), T(16));
  STF_EQUAL(bs::sqr_abs(r1), T(16));
  STF_EQUAL(bs::sqr_abs(r2), T(18));
  STF_EQUAL(bs::sqr_abs(r3), T(1));
  STF_EQUAL(bs::sqr_abs(r4), T(1));
  STF_EQUAL(bs::sqr_abs(r5), T(8));
}

STF_CASE_TPL( "Complex sqr_abs complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;

  p_t r{4, 3, -1, 0};
  p_t i{0, 3, 0 ,-2};

  bs::complex<p_t> r0{r,i};

  STF_EQUAL(bs::sqr_abs(r0) , (p_t{16,18,1,4}));
}

// template < class T >
// struct sqr_abs
// {
//   bs::complex<T> operator()(std::complex < T >  const & a)
//   {
//     return { a.real,  a.imag};
//   }
// };
template < class T >
T sqr_abs(std::complex < T >  const & a)
{
  bs::complex<T> z(a);
  return bs::sqr_abs(z);
}

STF_CASE_TPL( "Complex sqr_abs std::complex<T>", STF_IEEE_TYPES)
{
  using c_t  = std::complex<T>;
  using bc_t = bs::complex<T>;
  c_t a(2, 3);

  T z1 = std::norm(a);
  auto c2 = bc_t(a);
  T z2 = bs::sqr_abs(c2);
  T z4 = bs::sqr_abs(bc_t(a));
  T z5 = sqr_abs(a);
  STF_ULP_EQUAL(z1, z2, 0.5);
  STF_ULP_EQUAL(z1, z5, 0.5);
  STF_ULP_EQUAL(z1, z4, 0.5);
}
