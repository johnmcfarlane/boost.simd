//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/log10.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/log_10.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex log10 on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(-2, 0);
  STF_ULP_EQUAL( bs::cmplx::log10(c1), bs::complex<T>(0.30102999566398119521373889472449, 0.68218817692092067374289181271568), 0.5);
  STF_ULP_EQUAL( bs::cmplx::log10(c2), bs::complex<T>(0.69897000433601880478626110527551, 0.9616571575684682054078831650439), 1);
  STF_ULP_EQUAL( bs::cmplx::log10(c3), bs::complex<T>(0.30102999566398119521373889472449, 1.3643763538418413474857836254314), 0.5);
}

STF_CASE_TPL( "Complex log10 on T", STF_IEEE_TYPES)
{
  T r1(2), r2(-2);
  STF_ULP_EQUAL( bs::cmplx::log10(r1), bs::complex<T>(0.30102999566398119521373889472449, 0.0), 0.5);
  STF_ULP_EQUAL( bs::cmplx::log10(r2), bs::complex<T>(0.30102999566398119521373889472449, 1.3643763538418413474857836254314), 0.5);
  STF_ULP_EQUAL( bs::log10(r2), bs::Nan<T>(), 0.5);
}

STF_CASE_TPL( "Complex log10 complex<pack<T>>", STF_IEEE_TYPES)
{
    using p_t = bs::pack<T,4>;
    using cp_t = bs::complex<p_t>;
    p_t r(T(0), T(-3), T(-2), bs::Minf<T>()),  i(2, 4, 0, 1);
    p_t r1(T(0.30102999566398119521373889472449),
           T(0.69897000433601880478626110527551),
           T(0.30102999566398119521373889472449),
           bs::Inf<T>()),
      i1(T( 0.68218817692092067374289181271568),
         T(0.9616571575684682054078831650439),
         T(1.3643763538418413474857836254314),
         bs::Pi<T>()/bs::Log_10<T>() );
    cp_t c1(r, i),  c2(r1, i1);
    STF_ULP_EQUAL(bs::cmplx::log10(c1), c2, 01.0);
}




