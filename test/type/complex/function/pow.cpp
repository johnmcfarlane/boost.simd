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

  STF_ULP_EQUAL( bs::pow(T(2), T(4)), bs::complex<T>(T(16), T(0)), 0.5);
  STF_ULP_EQUAL( bs::pow(T(-16), T(0.25)),   bs::complex<T>(1.4142135623730950488016887242097, 1.4142135623730950488016887242097), 0.5);
  STF_ULP_EQUAL( bs::pow(T(16), T(0.25)), bs::complex<T>(2, 0), 0.5);
}

STF_CASE_TPL( "pow on pack<T>/pack<T>", STF_IEEE_TYPES)
{

  using p_t =  bs::pack<T, 4>;
  using cp_t =  bs::complex<p_t>;
  p_t x(2, -16, 16, 2),  y(4, 0.25, 0.25, -4);
  cp_t z(p_t(16.0, 1.4142135623730950488016887242097, 2, 0.0625),
       p_t(0.0, 1.4142135623730950488016887242097, 0, 0));
  STF_ULP_EQUAL( bs::pow(x, y), z, 0.5);

}

STF_CASE_TPL( "pow on complex<T>/complex<T>", STF_IEEE_TYPES)
{

  STF_ULP_EQUAL( bs::pow(T(2), T(4)), bs::complex<T>(T(16), T(0)), 0.5);
  STF_ULP_EQUAL( bs::pow(T(-16), T(0.25)),   bs::complex<T>(1.4142135623730950488016887242097, 1.4142135623730950488016887242097), 0.5);
  STF_ULP_EQUAL( bs::pow(T(16), T(0.25)), bs::complex<T>(2, 0), 0.5);
}

STF_CASE_TPL( "pow on T/pack<T>", STF_IEEE_TYPES)
{
  using p_t =  bs::pack<T, 4>;
  using cp_t =  bs::complex<p_t>;
  T x(-2);
  p_t y(4.0, 0.25, 0.25, -4.0);
  cp_t z(p_t(16.0, 0.84089641525371454303112547623321, 0.84089641525371454303112547623321, 0.0625),
       p_t(0, 0.84089641525371454303112547623321, 0.84089641525371454303112547623321, 0));
  STF_ULP_EQUAL( bs::pow(x, y), z, 0.5);

}

STF_CASE_TPL( "pow on pack<T>,  T", STF_IEEE_TYPES)
{
  using p_t =  bs::pack<T, 4>;
  using cp_t =  bs::complex<p_t>;
  T y(-0.5);
  p_t x(4.0, 0.25, -0.25, -4.0);
  cp_t z(p_t(0.5, 2.0, 0, 0),
         p_t(0, 0, -2.0, -0.5));
  STF_ULP_EQUAL( bs::pow(x, y), z, 0.5);

}
