//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/aligned_load.hpp>
#include <scalar_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Check misaligned aligned_load behavior with no target", STF_NUMERIC_TYPES )
{
  T data = static_cast<T>(42);
  T* ptr = &data - 2;

  STF_EQUAL( data, bs::aligned_load<+1>(&data+1));
  STF_EQUAL( data, bs::aligned_load< 0>(&data  ));
  STF_EQUAL( data, bs::aligned_load<-1>(&data-1));
  STF_EQUAL( data, bs::aligned_load<+1>(ptr+1,2));
  STF_EQUAL( data, bs::aligned_load< 0>(ptr  ,2));
  STF_EQUAL( data, bs::aligned_load<-1>(ptr-1,2));
}

STF_CASE_TPL( "Check misaligned aligned_load behavior with target", STF_NUMERIC_TYPES )
{
  T data = static_cast<T>(42);
  T* ptr = &data - 2;

  STF_EQUAL( data, (bs::aligned_load<T,+1>(&data+1)) );
  STF_EQUAL( data, (bs::aligned_load<T, 0>(&data  )) );
  STF_EQUAL( data, (bs::aligned_load<T,-1>(&data-1)) );
  STF_EQUAL( data, (bs::aligned_load<T,+1>(ptr+1,2)) );
  STF_EQUAL( data, (bs::aligned_load<T, 0>(ptr  ,2)) );
  STF_EQUAL( data, (bs::aligned_load<T,-1>(ptr-1,2)) );
}
/*
STF_CASE_TPL( "Check misaligned aligned_load behavior with target triggering conversion", STF_NUMERIC_TYPES )
{
  int data = -69;
  int* ptr = &data - 2;

  STF_EQUAL( static_cast<T>(data), bs::aligned_load<T>(&data));
  STF_EQUAL( static_cast<T>(data), bs::aligned_load<T>(ptr,2));
}
*/
