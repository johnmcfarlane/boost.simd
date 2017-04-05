//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [aligned_delete]
#include <boost/simd/memory/aligned_delete.hpp>
#include <boost/simd/memory/allocate.hpp>
#include <boost/simd/pack.hpp>
#include <memory>
#include <iostream>

int main()
{
  using boost::simd::allocate;
  std::unique_ptr<double, boost::simd::aligned_delete> ptr(allocate<double>(7));

  std::cout << ptr.get() << "\n";
}
//! [aligned_delete]
