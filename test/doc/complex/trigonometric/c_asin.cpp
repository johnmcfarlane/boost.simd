//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [asin]
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/asin.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/pi.hpp>
#include <iostream>

namespace bs = boost::simd;
using p_t  = bs::pack<float, 4>;
using cp_t = bs::complex<p_t>;

int main() {
  cp_t pf{p_t{1.0f, 2.0f, -1.0f, 0.5f}, p_t{0.0, 1.0, -1.0, 3.0}};

  std::cout << "---- simd" << '\n'
            << "<- pf =          " << pf << '\n'
            << "-> bs::asin(pf) = " << bs::asin(pf) << '\n';

  bs::complex<float> xf{0.0f, 1.0f};
  float yf{-2.0};

  std::cout << "---- scalar" << '\n'
            << "<- xf =                 " << xf << '\n'
            << "-> bs::asin(xf) =        " << bs::asin(xf) << '\n'
            << "<- yf =                 " << yf << '\n'
            << "-> bs::asin(yf) =        " << bs::asin(yf) << '\n'
            << "-> bs::cmplx::asin(yf) = " << bs::cmplx::asin(yf) << '\n';

  return 0;
}
//! [asin]
