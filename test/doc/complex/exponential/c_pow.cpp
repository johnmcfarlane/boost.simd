//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [pow]
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/pow.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using p_t  = bs::pack<float, 4>;
using c_t  = bs::complex<float>;
using cp_t = bs::complex<p_t>;

int main() {
  cp_t pf{p_t{0.0f, 2.0f, -1.0f, 0.5f}, p_t{0.0f, 1.0f, -1.0f, 3.0f}};
  cp_t qf{p_t{0.0f, 1.0f, -1.0f, 3.0f}, p_t{0.0f, 2.0f, -1.0f, 0.5f}};
  std::cout << "---- simd" << '\n'
            << " <- pf =              " << pf << '\n'
            << " <- qf =              " << qf << '\n'
            << " -> bs::pow(pf, qf) = " << bs::pow(pf, qf) << '\n';

  c_t xf = c_t{-1.0f, 1.5f}, yf = {4.0f, -0.5f}, zf = {0.0f, 0.0f};
  float r1f = -1.0f,  r2f = 1.5f;
  std::cout << "---- scalar" << '\n'
            << " xf =                          " << xf << '\n'
            << " yf =                          " << yf << '\n'
            << " -> bs::pow(xf, yf) =          " << bs::pow(xf, yf) << '\n'
            << " zf =                          " << zf << '\n'
            << " -> bs::pow(zf, zf) =          " << bs::pow(zf, zf) << '\n'
            << " r1f =                         " << r1f << '\n'
            << " r2f =                         " << r2f << '\n'
            << " -> bs::pow(r1f, r2f) =        " << bs::pow(r1f, r2f) << '\n'
            << " -> bs::cmplx::pow(r1f, r2f) = " << bs::cmplx::pow(r1f, r2f) << '\n';
  return 0;
}
//! [pow]
