//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [is_aligned]
#include <boost/simd/memory/allocate.hpp>
#include <boost/simd/memory/deallocate.hpp>
#include <boost/simd/memory/is_aligned.hpp>
#include <iostream>

int main()
{
  float* ptr1 = boost::simd::allocate<float>(15);
  float* ptr2 = boost::simd::allocate<float>(15, boost::simd::avx);

  std::cout << std::boolalpha << boost::simd::is_aligned(ptr1) << "\n";
  std::cout << std::boolalpha << boost::simd::is_aligned(ptr2, boost::simd::avx) << "\n";

   boost::simd::deallocate(ptr1);
   boost::simd::deallocate(ptr2);
}
//! [is_aligned]
