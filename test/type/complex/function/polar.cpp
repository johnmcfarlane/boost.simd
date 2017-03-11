//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/polar.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <boost/simd/function/sincos.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/sqrt_2.hpp>
#include <simd_test.hpp>


namespace bs = boost::simd;

STF_CASE_TPL( "polar on T/T", STF_IEEE_TYPES)
{

  STF_ULP_EQUAL( bs::polar(T(1), bs::Pi<T>()/2), bs::complex<T>(T(0), T(1)), 1.0);
  STF_ULP_EQUAL( bs::polar(T(1), bs::Pi<T>()),   bs::complex<T>(-1, 0), 1.0);
  STF_ULP_EQUAL( bs::polar(bs::Sqrt_2<T>(), bs::Pi<T>()/4),    bs::complex<T>(1, 1), 1.0);
  STF_ULP_EQUAL( bs::polar(T(1), T(0)), bs::complex<T>(1, 0), 1.0);
}

STF_CASE_TPL( "polar on pack<T>/pack<T>", STF_IEEE_TYPES)
{

  using p_t =  bs::pack<T, 4>;
  using cp_t =  bs::complex<p_t>;
  p_t r(2);
  p_t t = bs::enumerate<p_t>()*bs::Pi<T>()/4;
  p_t s, c;
  std::tie(s, c) = bs::sincos(t);
  STF_ULP_EQUAL(bs::polar(r, t), cp_t(c*2, s*2), 1.0);

}

STF_CASE_TPL( "polar on T/pack<T>", STF_IEEE_TYPES)
{

  using p_t =  bs::pack<T, 4>;
  using cp_t =  bs::complex<p_t>;
  p_t t = bs::enumerate<p_t>()*bs::Pi<T>()/4;
  p_t s, c;
  std::tie(s, c) = bs::sincos(t);
  STF_ULP_EQUAL(bs::polar(2, t), cp_t(c*2, s*2), 1.0);

}

STF_CASE_TPL( "polar on pack<T>,  T", STF_IEEE_TYPES)
{

  using p_t =  bs::pack<T, 4>;
  using cp_t =  bs::complex<p_t>;
  p_t r = bs::enumerate<p_t>();
  T s, c;
  std::tie(s, c) = bs::sincos(bs::Pi<T>()/4);
  STF_ULP_EQUAL(bs::polar(r, bs::Pi<T>()/4), cp_t(c*r, s*r), 1.0);

}
