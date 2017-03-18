// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor polar in std mode for double type with no decorator (regular call).
#include <simd_bench.hpp>
#include <complex>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

struct polar_bench
{
  template < class T >
  BOOST_FORCEINLINE std::complex<T> operator()(const T & a0, const T & a1)
    const BOOST_NOEXCEPT
  {
    return std::polar(a0, a1);
  }
};

DEFINE_BENCH_MAIN()
{
  using T = float;
  run<T>(polar_bench(), nsbg::rand<T>(-10, 10), nsbg::rand<T>(-10, 10));
}
