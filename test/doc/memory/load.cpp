//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [load]
#include <boost/simd/function/load.hpp>
#include <boost/simd/mask.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>
#include <vector>
#include <list>

int main()
{
  using boost::simd::load;
  using boost::simd::pack;
  using boost::simd::mask;

  std::int32_t       a[] = {1,2,3,4,5,6,7,8};
  std::vector<float> v{0.1f,0.01f,0.001f,0.0001f,0.00001f};
  std::list<double>  l{0.1,0.01};

  std::cout << "Scalar :\n";
  std::cout << " - load<std::int32_t>(&a[2]) : " << load<std::int32_t>(&a[2]) << "\n";
  std::cout << " - load<float>(v.begin())    : " << load<float>(v.begin()) << "\n";
  std::cout << " - load<double>(l.begin(),1) : " << load<double>(l.begin(),1) << "\n";
  std::cout << std::endl;

  std::cout << "Pack :\n";
  std::cout << " - load<pack<std::int32_t,4>>(&a[2])        : " << load<pack<std::int32_t,4>>(&a[2]) << "\n";
  std::cout << " - load<pack<float,4>>(v.begin())           : " << load<pack<float,4>>(v.begin()) << "\n";
  std::cout << " - load<pack<float,4>>(v.data(),1)          : " << load<pack<float,4>>(v.data(),1) << "\n";
  std::cout << " - load<pack<double, 2>>(l.begin(),l.end()) : " << load<pack<double, 2>>(l.begin(),l.end()) << "\n";
  std::cout << std::endl;

  pack<std::int32_t,4> x(&a[0]);
  std::cout << "Mask :\n";
  std::cout << " - load<pack<std::int32_t,4>>(mask(&a[0],[0,1,0,1]) : "
            << load<pack<std::int32_t,4>>( mask(&a[0], (x%2 == 0)) ) << "\n";

}
//! [load]
