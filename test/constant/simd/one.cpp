//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/pack.hpp>
#include <algorithm>

#include <simd_test.hpp>

namespace bs = boost::simd;

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  using p_t = bs::pack<T, N>;
  auto are_correct = [](T e) { return e == T(1); };
  auto p = bs::One<p_t>();
  STF_EXPECT(( std::all_of(p.begin() , p.end(), are_correct ) ));
}

STF_CASE_TPL("Check One<T> behavior" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

template <typename T, std::size_t N, typename Env>
void test_as(Env& runtime)
{
  using p_t = bs::pack<T, N>;
  auto are_correct = [](T e) { return e == T(1); };
  auto p = bs::One(bs::as_<p_t>());

  STF_EXPECT(( std::all_of(p.begin() , p.end(), are_correct ) ));
}

STF_CASE_TPL("Check One(as<T>) behavior" , STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test_as<T, N>(runtime);
  test_as<T, N/2>(runtime);
  test_as<T, N*2>(runtime);
}
