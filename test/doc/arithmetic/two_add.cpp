//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [two_add]
#include <boost/simd/arithmetic.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/eps.hpp>
#include <iostream>
#include <iomanip>

namespace bs =  boost::simd;
using pack_ft =  bs::pack <float, 4>;

int main()
{
  pack_ft pf = { 1.0f, -2.0f, 3.0f, -4.0 };
  pack_ft qf(bs::Eps<float>());
  auto pr = bs::two_add(pf, qf);
  std::cout
    <<  "---- simd" << std::setprecision(8) << '\n'
    << " <- pf =                                   " << pf << '\n'
    << " <- qf =                                   " << qf << '\n'
    << "  auto pr = bs::two_add(pf, qf)    " << '\n'
    << " ->  pr.low  =                             " << pr.low << '\n'
    << " ->  pr.high =                             " << pr.high << '\n';

  float xf = 3.0f, yf = bs::Eps<float>();
  auto sr = bs::two_add(xf, yf);
  std::cout
    << "---- scalar"  << '\n'
    << " xf =                                     " << xf << '\n'
    << " yf =                                     " << yf << '\n'
    << "  auto sr = bs::two_add(xf, yf)  " << '\n'
    << " ->  sr.low  =                            " << ss << '\n'
    << " ->  sr.high =                            " << se << '\n';

  return 0;
}
//! [two_add]
