//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/tanh.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/minf.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex tanh on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::tanh(c1), bs::complex<T>(0.0, -2.1850398632615189916433061023137), 0.5);
  STF_ULP_EQUAL( bs::tanh(c2), bs::complex<T>(-1.0007095360672329393295854724042, 0.0049082580674960602590787869299328), 0.5);
  STF_ULP_EQUAL( bs::tanh(c3), bs::complex<T>( 1.083923327338694543475752061212, 0.27175258531951171652884372249859), 1.0);
}

STF_CASE_TPL ( "tanh complex limits",STF_IEEE_TYPES)
{

  using bs::tanh;
  using bs::tag::tanh_;
  using cT = bs::complex<T>;

  {
    const int N = 2;
    cT inputs[N] =
      { cT(bs::Zero<T>(),bs::Zero<T>()), //0
        cT(bs::Zero<T>(),bs::Pi <T>()),  //16
      };

    cT results[N] =
      { cT(bs::Zero<T>(),bs::Zero<T>()),//0
        cT(bs::Zero<T>(),bs::Zero<T>()),//16
      };

    for(int i=0; i < N; i++)
    {
      STF_ULP_EQUAL(bs::tanh(inputs[i]), results[i], 1);
      STF_ULP_EQUAL(bs::tanh(-inputs[i]), -results[i], 1);
    }
  }
#ifndef BOOST_SIMD_NO_INVALIDS
  {
    const int N = 20;
    cT inputs[N] =
      { cT(bs::Zero<T>(),bs::Zero<T>()), //0
        cT(bs::Inf<T>(),bs::Zero<T>()),  //1
        cT(bs::Minf<T>(),bs::Zero<T>()), //2
        cT(bs::Nan<T>(),bs::Zero<T>()),  //3
        cT(bs::Zero<T>(),bs::Inf<T>()),  //4
        cT(bs::Inf<T>(),bs::Inf<T>()),   //5
        cT(bs::Minf<T>(),bs::Inf<T>()),  //6
        cT(bs::Nan<T>(),bs::Inf<T>()),   //7
        cT(bs::Zero<T>(),bs::Minf<T>()), //8
        cT(bs::Inf<T>(),bs::Minf<T>()),  //9
        cT(bs::Minf<T>(),bs::Minf<T>()), //10
        cT(bs::Nan<T>(),bs::Minf<T>()),  //11
        cT(bs::Zero<T>(),bs::Nan<T>()),  //12
        cT(bs::Inf<T>(),bs::Nan<T>()),   //13
        cT(bs::Minf<T>(),bs::Nan<T>()),  //14
        cT(bs::Nan<T>(),bs::Nan<T>()),   //15
        cT(bs::Zero<T>(),bs::Pi <T>()),  //16
        cT(bs::Inf<T>(),bs::Pi <T>()),   //17
        cT(bs::Minf<T>(),bs::Pi <T>()),  //18
        cT(bs::Nan<T>(),bs::Pi <T>()),   //19
      };

    cT results[N] =
      { cT(bs::Zero<T>(),bs::Zero<T>()),//0
        cT(bs::Nan<T>(),bs::Zero<T>()), //1
        cT(bs::Nan<T>(),bs::Zero<T>()), //2
        cT(bs::Nan<T>(),bs::Zero<T>()), //3
        cT(bs::Zero<T>(),bs::Nan<T>()), //4
        cT(bs::Nan<T>(),bs::Nan<T>()),  //5
        cT(bs::Nan<T>(),bs::Nan<T>()),  //6
        cT(bs::Nan<T>(),bs::Nan<T>()),  //7
        cT(bs::Zero<T>(),bs::Nan<T>()), //8
        cT(bs::Nan<T>(),bs::Nan<T>()),  //9
        cT(bs::Nan<T>(),bs::Nan<T>()),  //10
        cT(bs::Nan<T>(),bs::Nan<T>()),  //11
        cT(bs::Zero<T>(),bs::Nan<T>()), //12
        cT(bs::Nan<T>(),bs::Nan<T>()),  //13
        cT(bs::Nan<T>(),bs::Nan<T>()),  //14
        cT(bs::Nan<T>(),bs::Nan<T>()),  //15
        cT(bs::Zero<T>(),bs::Zero<T>()),//16
        cT(bs::Nan<T>(),bs::Zero<T>()), //17
        cT(bs::Nan<T>(),bs::Zero<T>()), //18
        cT(bs::Nan<T>(),bs::Nan <T>()), //19
      };

    for(int i=0; i < N; i++)
    {
      STF_ULP_EQUAL(bs::tanh(inputs[i]), results[i], 1);
      STF_ULP_EQUAL(bs::tanh(-inputs[i]), -results[i], 1);
    }
#endif
  }

} // end of test for floating_
