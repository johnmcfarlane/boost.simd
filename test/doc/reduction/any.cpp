//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [any]
#include <boost/simd/pack.hpp>
#include <boost/simd/reduction.hpp>
#include <iostream>

namespace bs = boost::simd;
using pack_ft = bs::pack<float, 4>;

int main() {
  pack_ft pf = {0.0f, 0.0f, -0.0f, 0.0f};
  pack_ft qf = {1.0f, 0.0f, -1.0f, 0.5f};

  std::cout << "---- simd" << '\n'
            << "<- pf =          " << pf << '\n'
            << "-> bs::any(pf) = " << bs::any(pf) << '\n'
            << "<- qf =          " << qf << '\n'
            << "-> bs::any(qf) = " << bs::any(qf) << '\n';

  return 0;
}
//! [any]
