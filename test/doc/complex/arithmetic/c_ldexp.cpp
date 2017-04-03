//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [ldexp]
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/ldexp.hpp>
#include <boost/simd/function/asin.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/pi.hpp>
#include <iostream>

namespace bs = boost::simd;
using p_t  = bs::pack<float, 4>;
using i_t  = bs::pack<int32_t, 4>;
using cp_t = bs::complex<p_t>;

int main() {
  cp_t pf{p_t{1.0f, 2.0f, -1.0f, 0.5f},p_t{0, 1, -1, 3}};
   i_t pi{0, 1, -1, 3};

  std::cout << "---- simd" << '\n'
            << "<- pf =                " << pf << '\n'
            << "<- pi =                " << pi << '\n'
            << "-> bs::ldexp(pf, pi) = " << bs::ldexp(pf, pi) << '\n';

  bs::complex<float> xf{1, 1};
  int32_t yi = 2;

  std::cout << "---- scalar" << '\n'
            << "<- xf =                " << xf << '\n'
            << "<- yi =                " << yi << '\n'
            << "-> bs::ldexp(xf, yi) = " << bs::ldexp(xf, yi) << '\n';
  return 0;
}
//! [ldexp]
