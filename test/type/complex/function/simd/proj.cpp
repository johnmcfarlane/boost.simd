//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/proj.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex proj complex<pack<T>>", STF_IEEE_TYPES)
{
   using p_t = bs::pack<T,4>;
   using cp_t = bs::complex<p_t>;
   p_t r0(T(1), bs::Inf<T>(), bs::Minf<T>(), T(1));
   p_t i0(bs::Inf<T>(), bs::Minf<T>(), T(1), T(-1));
   p_t r1(bs::Inf<T>(), bs::Inf<T>(), bs::Inf<T>(), T(1));
   p_t i1(T(0.0), T(-0.0), T(-0.0), T(-1));
   cp_t c1(r0, i0), c2(r1, i1);
   STF_IEEE_EQUAL( bs::proj(c1), c2);

}

