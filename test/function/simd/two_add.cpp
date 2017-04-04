//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/two_add.hpp>
#include <boost/simd/constant/eps.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;

  T a1[N], a2[N], r1[N], r2[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(i) : T(-i);
     a2[i] = (i%2) ? T(i+N) :T(-(i+2*N*bs::Eps<T>()));

    auto rr = bs::two_add(a1[i], a2[i]);
    r1[i] = rr.low;
    r2[i] = rr.high;
  }

  p_t aa1(&a1[0], &a1[0]+N);
  p_t aa2(&a2[0], &a2[0]+N);

  p_t rr1(&r1[0], &r1[0]+N);
  p_t rr2(&r2[0], &r2[0]+N);

  auto rrr = bs::two_add(aa1, aa2);
  STF_IEEE_EQUAL(rrr.low, rr1);
  STF_IEEE_EQUAL(rrr.high, rr2);
}

STF_CASE_TPL("Check two_add on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}
