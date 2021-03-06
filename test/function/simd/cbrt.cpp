//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/cbrt.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/std.hpp>
#include <simd_test.hpp>


namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::cbrt(a1[i]) ;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_ULP_EQUAL(bs::cbrt(aa1), bb,0.5);
}

STF_CASE_TPL("Check cbrt on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

STF_CASE_TPL (" cbrt",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::cbrt;
  using p_t = bs::pack<T>;

  using r_t = decltype(cbrt(p_t()));

  // return type conformity test
  STF_EXPR_IS(cbrt(p_t()), p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(cbrt(bs::Inf<p_t>()), bs::Inf<r_t>(), 0.5);
  STF_ULP_EQUAL(cbrt(bs::Minf<p_t>()), bs::Minf<r_t>(), 0.5);
  STF_ULP_EQUAL(cbrt(bs::Nan<p_t>()), bs::Nan<r_t>(), 0.5);
#endif
  STF_ULP_EQUAL(cbrt(bs::Mone<p_t>()), bs::Mone<r_t>(), 0.5);
  STF_ULP_EQUAL(cbrt(bs::One<p_t>()), bs::One<r_t>(), 0.5);
  STF_ULP_EQUAL(cbrt(bs::Zero<p_t>()), bs::Zero<r_t>(), 0.5);
  STF_ULP_EQUAL(cbrt(T(8)), T(2), 0.5);
  STF_ULP_EQUAL(cbrt(T(27)),T(3), 0.5);
  STF_ULP_EQUAL(cbrt(T(-8)), T(-2), 0.5);
  STF_ULP_EQUAL(cbrt(T(-27)),T(-3), 0.5);
}


