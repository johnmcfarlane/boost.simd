//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [is_inf]
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/is_inf.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using p_t  = bs::pack<float, 4>;
using cp_t = bs::complex<p_t>;

int main() {
  cp_t pf{p_t{1.0f, 2.0f, -1.0f, 0.5f}, p_t{0.0, 1.0, -1.0, 3.0}};

  std::cout << "---- simd" << '\n'
            << "<- pf =             " << pf << '\n'
            << "-> bs::is_inf(pf) = " << bs::is_inf(pf) << '\n';

  bs::complex<float> xf{1, 1};

  std::cout << "---- scalar" << '\n'
            << "<- xf =             " << xf << '\n'
            << "-> bs::is_inf(xf) = " << bs::is_inf(xf) << '\n';
  return 0;
}
//! [is_inf]
