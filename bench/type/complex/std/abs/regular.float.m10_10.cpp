// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor abs in std mode for float type with no decorator (regular call).
#include <simd_bench.hpp>
#include <complex>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

struct abs_std
{
  template < typename T >
  BOOST_FORCEINLINE T operator()(const std::complex<T> & a0) const
  {
    return std::abs(a0);
  }
};

DEFINE_BENCH_MAIN()
{
  using T = std::complex<float>;
  run<T>(abs_std(), nsbg::rand<T>(-10, 10, -10, 10));
}

