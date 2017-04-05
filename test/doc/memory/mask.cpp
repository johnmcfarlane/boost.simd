//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [mask]
#include <boost/simd/pack.hpp>
#include <boost/simd/mask.hpp>
#include <boost/simd/function/load.hpp>
#include <iostream>

int main()
{
  using boost::simd::load;
  using pack_t = boost::simd::pack<float>;

  float data[] = {1,2,3,4};
  pack_t y{-1,1,-1,1};

  std::cout << "y     : " << y << "\n";
  std::cout << "y < 0 : " << (y < 0) << "\n";

  std::cout << "Loaded value: " << load<pack_t>( &data[0] ) << "\n";
  std::cout << "Masked value: " << load<pack_t>( boost::simd::mask(&data[0], y<0) ) << "\n";
}
//! [mask]
