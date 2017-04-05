//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [aligned_object]
#include <iostream>
#include <boost/simd/pack.hpp>
#include <boost/simd/memory/aligned_object.hpp>

class custom_type
{
  public:
  BOOST_SIMD_ALIGNED_OBJECT(custom_type);

  private:
  boost::simd::pack<float> p;
};

int main()
{
  std::cout << alignof( custom_type ) << "\n";
}
//! [aligned_object]
