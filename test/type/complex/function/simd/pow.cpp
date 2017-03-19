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

STF_CASE_TPL( "pow on pack<T>/pack<T>", STF_IEEE_TYPES)
{

  using p_t =  bs::pack<T, 4>;
  using cp_t =  bs::complex<p_t>;
  p_t x(2, -16, 16, 2),  y(4, 0.25, 0.25, -4);
  cp_t z(p_t(16.0, 1.4142135623730950488016887242097, 2, 0.0625),
       p_t(0.0, 1.4142135623730950488016887242097, 0, 0));
  STF_ULP_EQUAL( bs::cmplx::pow(x, y), z, 0.5);

}

STF_CASE_TPL( "pow on T/pack<T>", STF_IEEE_TYPES)
{
  using p_t =  bs::pack<T, 4>;
  using cp_t =  bs::complex<p_t>;
  T x(-2);
  p_t y(4.0, 0.25, 0.25, -4.0);
  cp_t z(p_t(16.0, 0.84089641525371454303112547623321, 0.84089641525371454303112547623321, 0.0625),
       p_t(0, 0.84089641525371454303112547623321, 0.84089641525371454303112547623321, 0));
  STF_ULP_EQUAL( bs::cmplx::pow(x, y), z, 0.5);

}

STF_CASE_TPL( "pow on pack<T>,  T", STF_IEEE_TYPES)
{
  using p_t =  bs::pack<T, 4>;
  using cp_t =  bs::complex<p_t>;
  T y(-0.5);
  p_t x(4.0, 0.25, -0.25, -4.0);
  cp_t z(p_t(0.5, 2.0, 0, 0),
         p_t(0, 0, -2.0, -0.5));
  STF_ULP_EQUAL( bs::cmplx::pow(x, y), z, 0.5);

}

STF_CASE_TPL( "pow on complex<pack<T>>/complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t =  bs::pack<T, 4>; 
  using cp_t =  bs::complex<p_t>;
  cp_t x(p_t(1, 2, 3, 4), p_t(4, 3, 2, 1));
  cp_t y(p_t(4, -3, 2, -1), p_t(1, 2, 3, 4));
  p_t r(69.551320319011235556532865307327, 0.0027714167514021310793214453455137, 0.68176651908903392711589876067026, 0.05927410161490315431417514071668);
  p_t i(32.462776472692491366800631888044, -0.0011179825616529569706035126753128, -2.1207457766159625529219252086952, -0.069092581418823485059873847747483); 
  cp_t z(r, i);
  STF_ULP_EQUAL( bs::pow(x, y), z, 5.0);

}


STF_CASE_TPL( "pow on pack<T>/complex<pack<T>>", STF_IEEE_TYPES)
{
 using p_t =  bs::pack<T, 4>; 
  using cp_t =  bs::complex<p_t>;
  p_t x(p_t(1, 2, 3, 4));
  cp_t y(p_t(4, -3, 2, -1), p_t(1, 2, 3, 4));
  p_t r(1.0, 0.022932121842912709604992654601154, -8.8931513442797186948734782808862, 0.18495259164850763644379012858183);
  p_t i(0, 0.12287846755140546507327060629284, -1.382699955787889757249969902155, -0.16820386096193030994353489867342); 
  cp_t z(r, i);
  STF_ULP_EQUAL( bs::pow(x, y), z, 10.0);
}

STF_CASE_TPL( "pow on complex<pack<T>>,  pack<T>", STF_IEEE_TYPES)
{
  using p_t =  bs::pack<T, 4>; 
  using cp_t =  bs::complex<p_t>;
  cp_t x(p_t(1, 2, 3, 4), p_t(4, 3, 2, 1));
  p_t y(4, -3, 2, -1);
  p_t r(161.0, -0.020937642239417387346381429221666, 5.0, 0.23529411764705882352941176470588); 
  p_t i(-240.0, -0.004096495220755575785161583978152, 12.0, -0.058823529411764705882352941176471); 
  cp_t z(r, i);
  STF_ULP_EQUAL( bs::pow(x, y), z, 5.0);

}
