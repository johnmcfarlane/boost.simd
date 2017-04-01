//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/cosh.hpp>
#include <boost/simd/type/complex/function/mul_i.hpp>
#include <boost/simd/type/complex/function/cos.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/minf.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex cosh on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(1, 1);
  STF_ULP_EQUAL( bs::cosh(c1), bs::complex<T>(-0.41614683654714238699756822950076, 0), 0.5);
  STF_ULP_EQUAL( bs::cosh(c2), bs::complex<T>(- 6.5806630405511564325607441265388, 7.581552742746544353716345286538), 0.5);
  STF_ULP_EQUAL( bs::cosh(c3), bs::complex<T>(0.83373002513114904888388539433509, 0.98889770576286509638212954089269), 1.0);
}


STF_CASE_TPL ( "cosh limiting values", STF_IEEE_TYPES)
{

  using bs::cosh;
  using c_t =  bs::complex<T>;
  {
    const int N = 2;
    T Pie =  bs::Pi <T>()-bs::Eps<T>();
    c_t inputs[] =
      { c_t(bs::Zero<T>(),bs::Zero<T>()),//0   c_t(bs::One<T>(), bs::Zero<T>()),//0 ok
        c_t(bs::Zero<T>(),Pie),           //16  c_t(bs::Mone<T>(),bs::Zero<T>()),//16
      };

    c_t results[] =
      { c_t(bs::One<T>(), bs::Zero<T>()),//0
        c_t(bs::Mone<T>(),bs::Zero<T>()),//16
      };

    for(int i=0; i < N; i++)
    {
      STF_IEEE_EQUAL(bs::cosh(inputs[i]), results[i]);
      STF_IEEE_EQUAL(bs::cosh(-inputs[i]), bs::cosh(inputs[i]));
      STF_IEEE_EQUAL(bs::cosh(inputs[i]), bs::cos(bs::mul_i(inputs[i])));
    }
  }
  std::cout << "------------------------------------------" << std::endl;
#ifndef BOOST_SIMD_NO_INVALIDS
  {
    const int N = 20;
    T Pie =  bs::Pi <T>()-bs::Eps<T>();
    c_t inputs[N] =
      { c_t(bs::Zero<T>(),bs::Zero<T>()),//0   c_t(bs::One<T>(), bs::Zero<T>()),//0 ok
        c_t(bs::Inf<T>(),bs::Zero<T>()), //1   c_t(bs::Inf<T>(),bs::Zero<T>()), //1 ok
        c_t(bs::Minf<T>(),bs::Zero<T>()),//2   c_t(bs::Inf<T>(),bs::Zero<T>()), //2 ok
        c_t(bs::Nan<T>(),bs::Zero<T>()), //3   c_t(bs::Nan<T>(),bs::Zero<T>()), //3 ok
        c_t(bs::Zero<T>(),bs::Inf<T>()), //4   c_t(bs::Nan<T>(), bs::Zero<T>()),//4 ok
        c_t(bs::Inf<T>(),bs::Inf<T>()),  //5   c_t(bs::Inf<T>(),bs::Nan<T>()),  //5 ok
        c_t(bs::Minf<T>(),bs::Inf<T>()), //6   c_t(bs::Inf<T>(),bs::Nan<T>()),  //6
        c_t(bs::Nan<T>(),bs::Inf<T>()),  //7   c_t(bs::Nan<T>(),bs::Nan<T>()),  //7
        c_t(bs::Zero<T>(),bs::Minf<T>()),//8   c_t(bs::Nan<T>(), bs::Zero<T>()),//8
        c_t(bs::Inf<T>(),bs::Minf<T>()), //9   c_t(bs::Inf<T>(),bs::Nan<T>()),  //9
        c_t(bs::Minf<T>(),bs::Minf<T>()),//10  c_t(bs::Inf<T>(),bs::Nan<T>()),  //10
        c_t(bs::Nan<T>(),bs::Minf<T>()), //11  c_t(bs::Nan<T>(),bs::Nan<T>()), //11
        c_t(bs::Zero<T>(),bs::Nan<T>()), //12  c_t(bs::Zero<T>(),bs::Nan<T>()), //12
        c_t(bs::Inf<T>(),bs::Nan<T>()),  //13  c_t(bs::Inf<T>(),bs::Nan<T>()),  //13
        c_t(bs::Minf<T>(),bs::Nan<T>()), //14  c_t(bs::Inf<T>(),bs::Nan<T>()), //14
         c_t(bs::Nan<T>(),bs::Nan<T>()),  //15  c_t(bs::Nan<T>(),bs::Nan<T>()),  //15
        c_t(bs::Zero<T>(),Pie),           //16  c_t(bs::Mone<T>(),bs::Zero<T>()),//16
        c_t(bs::Inf<T>(),Pie),            //17  c_t(bs::Minf<T>(),bs::Inf<T>()), //17
         c_t(bs::Minf<T>(),Pie),           //18  c_t(bs::Minf<T>(),bs::Minf<T>()),//18
        c_t(bs::Nan<T>(),Pie),            //19  c_t(bs::Nan<T>(),bs::Nan <T>()),  //19
      };

    c_t results[] =
      { c_t(bs::One<T>(), bs::Zero<T>()),//0
        c_t(bs::Inf<T>(),bs::Zero<T>()), //1
        c_t(bs::Inf<T>(),bs::Zero<T>()), //2
        c_t(bs::Nan<T>(),bs::Zero<T>()), //3
        c_t(bs::Nan<T>(), bs::Zero<T>()),//4
        c_t(bs::Inf<T>(),bs::Nan<T>()),  //5
        c_t(bs::Inf<T>(),bs::Nan<T>()),  //6
        c_t(bs::Nan<T>(),bs::Nan<T>()),  //7
        c_t(bs::Nan<T>(), bs::Zero<T>()),//8
        c_t(bs::Inf<T>(),bs::Nan<T>()),  //9
        c_t(bs::Inf<T>(),bs::Nan<T>()),  //10
        c_t(bs::Nan<T>(),bs::Nan<T>()),  //11
        c_t(bs::Nan<T>(),bs::Zero<T>()), //12
        c_t(bs::Inf<T>(),bs::Nan<T>()),  //13
        c_t(bs::Inf<T>(),bs::Nan<T>()),  //14
        c_t(bs::Nan<T>(),bs::Nan<T>()),  //15
        c_t(bs::Mone<T>(),bs::Zero<T>()),//16
        c_t(bs::Minf<T>(),bs::Inf<T>()), //17
        c_t(bs::Minf<T>(),bs::Minf<T>()),//18
        c_t(bs::Nan<T>(),bs::Nan <T>()), //19
      };

    for(int i=0; i < N; i++)
    {
      std::cout << i <<  "-> " << inputs[i] << std::endl;
      STF_IEEE_EQUAL(bs::cosh(inputs[i]), results[i]);
      STF_IEEE_EQUAL(bs::cosh(-inputs[i]), bs::cosh(inputs[i]));
      STF_IEEE_EQUAL(bs::cosh(inputs[i]), bs::cos(bs::mul_i(inputs[i])));
    }
  }
#endif
} // end of test for floating_

