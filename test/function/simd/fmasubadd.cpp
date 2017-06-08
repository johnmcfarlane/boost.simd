//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/fmasubadd.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  T a0[N], a1[N], a2[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a0[i] = (i%2) ? T(-i) : T(i);
    a1[i] = (i%2) ? T(i) : T(2*i+1);
    a2[i] = (i%2) ? T(2*i) : T(i+3);
    b[i]  = i%2 ? a0[i] * a1[i] + a2[i] : a0[i] * a1[i] - a2[i];
  }

  p_t aa0(&a0[0], &a0[0]+N);
  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_EQUAL(bs::fmasubadd(aa0, aa1, aa2), bb);
}

STF_CASE_TPL("Check abs on pack" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}