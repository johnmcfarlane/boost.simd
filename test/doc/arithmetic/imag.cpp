//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [imag]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;
using pack_it = bs::pack <std::int16_t,4>;

int main()
{
  pack_ft pf = {-1.0f, 2.0f, -3.0f, -32768.0f};

  std::cout
    << "---- simd" << '\n'
    << "<- pf =                " << pf << '\n'
    << "-> bs::imag(pf) =      " << bs::imag(pf) << '\n'

  float xf = -32768.0f;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xf =                " << xf << '\n'
    << "-> bs::imag(xf) =      " << bs::imag(xf) << '\n'
  return 0;
}
//! [imag]
