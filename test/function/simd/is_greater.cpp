//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

// template <typename T, std::size_t N, typename Env>
// void test(Env& runtime)
// {
//   using p_t = bs::pack<T, N>;
//   using pl_t = bs::pack<bs::logical<T>, N>;

//   T a1[N], a2[N];
//   bs::logical<T> b[N];

//   for(std::size_t i = 0; i < N; ++i)
//   {
//     a1[i] = (i%2) ? T(i) : T(2*i);
//     a2[i] = (i%2) ? T(i) : T(2*i+1);
//     b[i] = bs::is_greater(a1[i], a2[i]);
//   }

//   p_t aa1(&a1[0], &a1[0]+N);
//   p_t aa2(&a2[0], &a2[0]+N);
//   pl_t bb(&b[0], &b[0]+N);

//   STF_EQUAL(bs::is_greater(aa1, aa2), bb);
//   STF_EQUAL(aa1 > aa2, bb);
// }

// STF_CASE_TPL("Check is_greater on pack", STF_NUMERIC_TYPES)
// {
//   static const std::size_t N = bs::pack<T>::static_size;

//   test<T, N>(runtime);
//   test<T, N/2>(runtime);
//   test<T, N*2>(runtime);
// }


STF_CASE_TPL (" is_greater real", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_greater;
  using p_t = bs::pack<T>;
  using r_t = decltype(is_greater(p_t(), p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::as_logical_t<p_t>);

  // specific values tests
// #ifndef BOOST_SIMD_NO_INVALIDS
//   STF_EQUAL(is_greater(bs::Inf<p_t>()), bs::One<r_t>());
//   STF_EQUAL(is_greater(bs::Minf<p_t>()), bs::Mone<r_t>());
//    STF_IEEE_EQUAL(is_greater(bs::Nan<p_t>()), bs::Nan<r_t>());
// #endif
  STF_EQUAL(is_greater(bs::Mone<p_t>(), bs::Zero<p_t>()), bs::False<r_t>());
//   STF_EQUAL(is_greater(bs::One<p_t>()), bs::One<r_t>());
//   STF_EQUAL(is_greater(bs::Zero<p_t>()), bs::Zero<r_t>());
}
