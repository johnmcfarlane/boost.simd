//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [log10]
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/exp.hpp>
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
            << "-> bs::log10(pf) = " << bs::log10(pf) << '\n';

  bs::complex<float> xf{0.0, bs::Pi<float>()};
  float yf{-1.0};

  std::cout << "---- scalar" << '\n'
            << "<- xf =                   " << xf << '\n'
            << "-> bs::log10(xf) =        " << bs::log10(xf) << '\n'
            << "<- yf =                   " << yf << '\n'
            << "-> bs::log10(yf) =        " << bs::log10(yf) << '\n'
            << "-> bs::cmplx::log10(yf) = " << bs::cmplx::log10(yf) << '\n';

  return 0;
//! [log10]
