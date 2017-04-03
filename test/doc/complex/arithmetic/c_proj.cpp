//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [proj]
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/proj.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/inf.hpp>
#include <iostream>

namespace bs = boost::simd;
using p_t  = bs::pack<float, 4>;
using cp_t = bs::complex<p_t>;

int main() {
  cp_t pf{p_t{1.0f, bs::Inf<float>(), -1.0f, bs::Nan<float>()}, p_t{0.0, 1.0, bs::Minf<float>(), 3.0}};

  std::cout << "---- simd" << '\n'
            << "<- pf =          " << pf << '\n'
            << "-> bs::proj(pf) = " << bs::proj(pf) << '\n';

  bs::complex<float> xf{1, bs::Minf<float>()};

  std::cout << "---- scalar" << '\n'
            << "<- xf =          " << xf << '\n'
            << "-> bs::proj(xf) = " << bs::proj(xf) << '\n';
  return 0;
}
//! [proj]
