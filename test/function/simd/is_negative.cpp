//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/logical.hpp>
#include <simd_test.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;
  using pl_t = bs::pack<bs::logical<T>, N>;

  T a1[N];
  bs::logical<T> b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i/2) : T(-i/2);
    b[i] = bs::is_negative(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  pl_t bb(&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::is_negative(aa1), bb);
}

STF_CASE_TPL("Check is_negative on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

STF_CASE_TPL (" is_negative values",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_negative;
  using p_t = bs::pack<T>;

 using r_t = decltype(is_negative(p_t()));

  // return type conformity test
 STF_TYPE_IS(r_t, bs::as_logical_t<p_t>);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_ULP_EQUAL(is_negative(bs::Inf<p_t>()), bs::False<p_t>(), 0);
  STF_ULP_EQUAL(is_negative(bs::Minf<p_t>()), bs::True<p_t>(), 0);
 std::cout << bs::Nan<p_t>() << std::endl;
   STF_ULP_EQUAL(is_negative(bs::Nan<p_t>()), bs::True<p_t>(), 0);
#endif
STF_ULP_EQUAL(is_negative(bs::Zero<p_t>()), bs::False<p_t>(), 0);
 std::cout << bs::Mzero<p_t>() << std::endl;
 STF_ULP_EQUAL(is_negative(bs::Mzero<p_t>()), bs::True<p_t>(), 0);
  STF_ULP_EQUAL(is_negative(bs::One<p_t>()),bs::False<p_t>(), 0.5);
  STF_ULP_EQUAL(is_negative(bs::Mone<p_t>()),bs::True<p_t>(), 0.5);
  STF_ULP_EQUAL(is_negative(bs::Half<p_t>()), bs::False<p_t>(), 0.5);
  STF_ULP_EQUAL(is_negative(bs::Mhalf<p_t>()),bs::True<p_t>(), 0.5);
}
