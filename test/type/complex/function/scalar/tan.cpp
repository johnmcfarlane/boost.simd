//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/tan.hpp>
#include <boost/simd/type/complex/function/mul_i.hpp>
#include <boost/simd/type/complex/function/mul_mi.hpp>
#include <boost/simd/type/complex/function/tanh.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/minf.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex tan on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::tan(c1), bs::complex<T>(0.0,  0.96402758007581688394641372410092), 0.5);
  STF_ULP_EQUAL( bs::tan(c2), bs::complex<T>(0.00018734620462947842622425563772822, 0.99935598738147314139164963032013), 0.5);
  STF_ULP_EQUAL( bs::tan(c3), bs::complex<T>( 0.27175258531951171652884372249859, 1.083923327338694543475752061212), 1.0);
}



 STF_CASE_TPL ( "complex tan limits",  STF_IEEE_TYPES)
{
  using bs::tan;
  using c_t =  bs::complex<T>;
  using s_t =  std::complex<T>;

  // specific values tests
  STF_ULP_EQUAL(bs::tan(c_t(bs::Inf<T>())), c_t(bs::Nan<T>()), 10);
  STF_ULP_EQUAL(bs::tan(c_t(bs::Minf<T>())), c_t(bs::Nan<T>()), 10);
  STF_ULP_EQUAL(bs::tan(c_t(1, 1)), c_t(std::tan(s_t(1.0, 1.0))), 10);
  STF_ULP_EQUAL(bs::tan(c_t(1, 0.5)), c_t(std::tan(s_t(1.0, 0.5))), 10);
  STF_ULP_EQUAL(bs::tan(c_t(0.5, 1)), c_t(std::tan(s_t(0.5, 1.0))), 10);
  STF_ULP_EQUAL(bs::tan(c_t(0.5, 0.5)), c_t(std::tan(s_t(0.5, 0.5))), 10);
  STF_ULP_EQUAL(bs::tan(c_t(0, 1)), c_t(std::tan(s_t(0.0, 1.0))), 10);
  STF_ULP_EQUAL(bs::tan(c_t(0, 0.5)), c_t(std::tan(s_t(0.0, 0.5))), 10);
  STF_ULP_EQUAL(bs::tan(c_t(0.5, 0)), c_t(std::tan(s_t(0.5, 0.0))), 10);

  const int N = 20;
  c_t inputs[N] =
    { c_t(bs::Zero<T>(),bs::Zero<T>()),c_t(bs::Inf<T>(),bs::Zero<T>()),c_t(bs::Minf<T>(),bs::Zero<T>()),c_t(bs::Nan<T>(),bs::Zero<T>()),
      c_t(bs::Zero<T>(),bs::Inf<T>()), c_t(bs::Inf<T>(),bs::Inf<T>()), c_t(bs::Minf<T>(),bs::Inf<T>()), c_t(bs::Nan<T>(),bs::Inf<T>()),
      c_t(bs::Zero<T>(),bs::Minf<T>()),c_t(bs::Inf<T>(),bs::Minf<T>()),c_t(bs::Minf<T>(),bs::Minf<T>()),c_t(bs::Nan<T>(),bs::Minf<T>()),
      c_t(bs::Zero<T>(),bs::Nan<T>()), c_t(bs::Inf<T>(),bs::Nan<T>()), c_t(bs::Minf<T>(),bs::Nan<T>()), c_t(bs::Nan<T>(),bs::Nan<T>()),
      c_t(bs::Zero<T>(),bs::Pi <T>()), c_t(bs::Inf<T>(),bs::Pi <T>()), c_t(bs::Minf<T>(),bs::Pi <T>()), c_t(bs::Nan<T>(),bs::Pi<T>()),
    };

  for(int i=0; i < N; i++)
   {
     STF_ULP_EQUAL(bs::tan(-inputs[i]), -bs::tan(inputs[i]), 3);
     STF_ULP_EQUAL(bs::tan(inputs[i]), bs::mul_mi(bs::tanh(bs::mul_i(inputs[i]))), 3);
   }


 }

