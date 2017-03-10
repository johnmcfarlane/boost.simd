//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [ifrexp]
#include <boost/simd/ieee.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_ft = bs::pack <float, 4>;
using pack_it = bs::pack <int32_t, 4>;

int main()
{
  pack_ft pf = {1.0f, 2.0f, -1.0f, 0.5f};
  auto pe = bs::ifrexp(pf);
  std::cout
    << "---- simd" << '\n'
    << "<- pf =                                 " << pf << '\n'
    << "-> pe = bs::ifrexp(pf) = " << '\n'
    << "-> pe.mantissa =                                " << pe.mantissa << '\n'
    << "-> pe.exponent =                                " << pe.exponent << '\n'   ;

  float xf = 2.0f;
  auto me = bs::ifrexp(xf);
  std::cout
    << "---- scalar"  << '\n'
    << " xf =                                   " << xf << '\n'
    << "-> me = bs::ifrexp(xf) =   " << '\n'
    << "-> m  =                                 " << me.mantissa << '\n'
    << "-> ie =                                 " << me.exponent << '\n'   ;

  return 0;
}
//! [ifrexp]
