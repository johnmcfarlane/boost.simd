//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [frexp]
#include <boost/simd/ieee.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;

int main()
{
  pack_ft pf = {1.0f, 2.0f, -1.0f, 0.5f};
  auto pfe = bs::frexp(pf);
  std::cout
    << "---- simd" << '\n'
    << "<- pf =                               " << pf << '\n'
    << "-> std::tie(pm, pe) = bs::frexp(pf) = " << '\n'
    << "-> pm  =                              " << pfe.mantissa << '\n'
    << "-> pie =                              " << pfe.exponent << '\n'   ;

  float xf = 2.0f;
  auto fe = bs::frexp(xf);
  std::cout
    << "---- scalar"  << '\n'
    << " xf =                                 " << xf << '\n'
    << "-> std::tie(m, e) = bs::frexp(xf) =   " << '\n'
    << "-> m  =                               " << fe.mantissa << '\n'
    << "-> e =                                " << fe.exponent << '\n'   ;

  return 0;
}
//! [frexp]
