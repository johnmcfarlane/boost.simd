//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [polar]
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/polar.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/pio_2.hpp>
#include <iostream>

namespace bs = boost::simd;
using p_t  = bs::pack<float, 4>;
using i_t  = bs::pack<int32_t, 4>;
using cp_t = bs::complex<p_t>;

int main() {
  p_t pf{1.0f, 2.0f, -1.0f, 0.5f};
  p_t tf{0.0f, 1.0f, -1.0f, 3.0f};


  std::cout << "---- simd" << '\n'
            << "<- pf =                " << pf << '\n'
            << "<- pi =                " << tf << '\n'
            << "-> bs::polar(pf, tf) = " << bs::polar(pf, tf) << '\n';

  float x{1.0f}, t{bs::Pio_2<float>()};


  std::cout << "---- scalar" << '\n'
            << "<- x =                " << x << '\n'
            << "<- t =                " << t << '\n'
            << "-> bs::polar(x, t) =  " << bs::polar(x, t) << '\n';
  return 0;
}
//! [polar]
