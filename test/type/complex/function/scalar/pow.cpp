//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/pow.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <boost/simd/function/sincos.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/sqrt_2.hpp>
#include <simd_test.hpp>


namespace bs = boost::simd;

STF_CASE_TPL( "pow on T/T", STF_IEEE_TYPES)
{

  STF_ULP_EQUAL( bs::cmplx::pow(T(2), T(4)), bs::complex<T>(T(16), T(0)), 0.5);
  STF_ULP_EQUAL( bs::cmplx::pow(T(-16), T(0.25)),   bs::complex<T>(1.4142135623730950488016887242097, 1.4142135623730950488016887242097), 0.5);
  STF_ULP_EQUAL( bs::cmplx::pow(T(16), T(0.25)), bs::complex<T>(2, 0), 0.5);
  STF_ULP_EQUAL( bs::cmplx::pow(T(0), T(0)), bs::complex<T>(1, 0), 0.5);
}

STF_CASE_TPL( "pow on complex<T>/complex<T>", STF_IEEE_TYPES)
{

  using cp_t =  bs::complex<T>;
  cp_t z(0);
  cp_t x(2, 3);
  cp_t y(1, 0.25);
  cp_t r(0.74509938112659227173925750456051, 2.7198994461260849240560206508983);
  STF_ULP_EQUAL( bs::pow(x, y), r, 1.0);
  STF_ULP_EQUAL( bs::pow(z, z), cp_t(1), 1.0);

}


STF_CASE_TPL( "pow on T/complex<T>", STF_IEEE_TYPES)
{
  using cp_t =  bs::complex<T>;
  T x(-2);
  cp_t y(1.0, 0.25);
  cp_t r(-0.89821942821603296853913520691995, -0.15722647416485059396946240479643);
  STF_ULP_EQUAL( bs::pow(x, y), r, 1.0);
  STF_ULP_EQUAL( bs::pow(T(0), cp_t(0)), cp_t(1), 1.0);

}

STF_CASE_TPL( "pow on complex<T>,  T", STF_IEEE_TYPES)
{
  using cp_t =  bs::complex<T>;
  T y(-0.5);
  cp_t x(1.0, 0.25);
  cp_t r(0.97757837811951609985504014263266, -0.12034539782870095269303954278421);
  STF_ULP_EQUAL( bs::pow(x, y), r, 1.0);
  STF_ULP_EQUAL( bs::pow(cp_t(0), T(0)), cp_t(1), 1.0);

}
