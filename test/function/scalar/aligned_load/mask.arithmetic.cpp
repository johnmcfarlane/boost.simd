//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/aligned_load.hpp>
#include <boost/simd/mask.hpp>
#include <scalar_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Check aligned_load behavior with no target & masked data with true", STF_NUMERIC_TYPES )
{
  T data = static_cast<T>(42);
  STF_EQUAL( data, bs::aligned_load(bs::mask(&data  , true    )   ) );
  STF_EQUAL( data, bs::aligned_load(bs::mask(&data  , true , 3)   ) );
  STF_EQUAL( data, bs::aligned_load(bs::mask(&data-2, true    ),2 ) );
  STF_EQUAL( data, bs::aligned_load(bs::mask(&data-2, true , 7),2 ) );
}

STF_CASE_TPL( "Check aligned_load behavior with no target & masked data with false", STF_NUMERIC_TYPES )
{
  T data = static_cast<T>(42);
  STF_EQUAL( T(0), bs::aligned_load(bs::mask(&data  , false     )   ) );
  STF_EQUAL( T(0), bs::aligned_load(bs::mask(&data-2, false     ),2 ) );
  STF_EQUAL( T(3), bs::aligned_load(bs::mask(&data  , false , 3 )   ) );
  STF_EQUAL( T(7), bs::aligned_load(bs::mask(&data-2, false , 7 ),2 ) );
}

STF_CASE_TPL( "Check aligned_load behavior with target & masked data with true", STF_NUMERIC_TYPES )
{
  T data = static_cast<T>(42);
  STF_EQUAL( data, bs::aligned_load<T>(bs::mask(&data  , true    )   ) );
  STF_EQUAL( data, bs::aligned_load<T>(bs::mask(&data  , true , 3)   ) );
  STF_EQUAL( data, bs::aligned_load<T>(bs::mask(&data-2, true    ),2 ) );
  STF_EQUAL( data, bs::aligned_load<T>(bs::mask(&data-2, true , 7),2 ) );
}

STF_CASE_TPL( "Check aligned_load behavior with target & masked data with false", STF_NUMERIC_TYPES )
{
  T data = static_cast<T>(42);
  STF_EQUAL( T(0), bs::aligned_load<T>(bs::mask(&data  , false     )   ) );
  STF_EQUAL( T(0), bs::aligned_load<T>(bs::mask(&data-2, false     ),2 ) );
  STF_EQUAL( T(3), bs::aligned_load<T>(bs::mask(&data  , false , 3 )   ) );
  STF_EQUAL( T(7), bs::aligned_load<T>(bs::mask(&data-2, false , 7 ),2 ) );
}

STF_CASE_TPL( "Check aligned_load behavior with target triggering conversion & masked data with true"
            , STF_NUMERIC_TYPES
            )
{
  int data = -69;

  STF_EQUAL( T(data), bs::aligned_load<T>(bs::mask(&data  , true    )   ) );
  STF_EQUAL( T(data), bs::aligned_load<T>(bs::mask(&data  , true , 3)   ) );
  STF_EQUAL( T(data), bs::aligned_load<T>(bs::mask(&data-2, true    ),2 ) );
  STF_EQUAL( T(data), bs::aligned_load<T>(bs::mask(&data-2, true , 7),2 ) );
}

STF_CASE_TPL( "Check aligned_load behavior with target triggering conversion & masked data with false"
            , STF_NUMERIC_TYPES
            )
{
  int data = -69;

  STF_EQUAL( T(0), bs::aligned_load<T>(bs::mask(&data  , false     )   ) );
  STF_EQUAL( T(0), bs::aligned_load<T>(bs::mask(&data-2, false     ),2 ) );
  STF_EQUAL( T(3), bs::aligned_load<T>(bs::mask(&data  , false , 3 )   ) );
  STF_EQUAL( T(7), bs::aligned_load<T>(bs::mask(&data-2, false , 7 ),2 ) );
}
