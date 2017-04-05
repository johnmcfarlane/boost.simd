//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [allocate]
#include <iostream>
#include <boost/simd/pack.hpp>
#include <boost/simd/memory/allocate.hpp>
#include <boost/simd/memory/deallocate.hpp>

int main()
{
  auto ptr1 = boost::simd::allocate<float>(33);
  std::cout << (void*)(ptr1) << "\n";

  auto ptr2 = boost::simd::allocate<float>(33, boost::simd::avx);
  std::cout << (void*)(ptr2) << "\n";

  boost::simd::deallocate(ptr1);
  boost::simd::deallocate(ptr2);
}
//! [allocate]
