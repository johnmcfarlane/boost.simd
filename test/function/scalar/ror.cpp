//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/ror.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/function/bitwise_cast.hpp>

STF_CASE_TPL (" rorinteger", STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::ror;
  STF_EXPR_IS( ror(T(), T()), T);

  T w = sizeof(T)*CHAR_BIT;

  for(T i=0;i<w;++i)
  {
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
    STF_EQUAL(ror(T(1),i), T(T(1)<<((w-i) & (w-1))));
  }
}
