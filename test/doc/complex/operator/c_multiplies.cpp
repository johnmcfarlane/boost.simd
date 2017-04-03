//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [multiplies]
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/multiplies.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using p_t  = bs::pack<float, 4>;
using cp_t = bs::complex<p_t>;

int main() {
  cp_t pf{p_t{1.0f, 2.0f, -1.0f, 0.5f}, p_t{0.0f, 1.0f, -1.0f, 3.0f}};
  cp_t qf{p_t{3.0f, 1.0f,  1.0f, 0.0f}, p_t{0.4f, 2.0f, -1.0f, 2.0f}};

  std::cout << "---- simd" << '\n'
            << "<- pf =          " << pf << '\n'
            << "<- qf =          " << qf << '\n'
            << "-> pf * qf    = " << (pf * qf) << '\n';

  bs::complex<float> xf{1, 1}, yf(1, 1);

  std::cout << "---- scalar" << '\n'
            << "<- xf =          " << xf << '\n'
            << "<- yf =          " << yf << '\n'
            << "-> xf * yf    = " <<(xf * yf) << '\n';
  return 0;
}
//! [multiplies]
