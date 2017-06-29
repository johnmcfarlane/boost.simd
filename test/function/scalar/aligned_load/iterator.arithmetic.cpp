//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/aligned_load.hpp>
#include <scalar_test.hpp>
#include <forward_list>

namespace bs = boost::simd;

STF_CASE_TPL( "Check aligned_load behavior with no target", STF_NUMERIC_TYPES )
{
  std::forward_list<T> data = { 42, 0, 69 };

  STF_EQUAL( T(42), bs::aligned_load(data.begin()));
  STF_EQUAL( T(69), bs::aligned_load(data.begin(),2));
}

STF_CASE_TPL( "Check aligned_load behavior with target", STF_NUMERIC_TYPES )
{
  std::forward_list<T> data = { 42, 0, 69 };

  STF_EQUAL( T(42), bs::aligned_load<T>(data.begin()));
  STF_EQUAL( T(69), bs::aligned_load<T>(data.begin(),2));
}

STF_CASE_TPL( "Check aligned_load behavior with target triggering conversion", STF_NUMERIC_TYPES )
{
  std::forward_list<int> data = { 42, 0, 69 };

  STF_EQUAL( T(42), bs::aligned_load<T>(data.begin()));
  STF_EQUAL( T(69), bs::aligned_load<T>(data.begin(),2));
}
