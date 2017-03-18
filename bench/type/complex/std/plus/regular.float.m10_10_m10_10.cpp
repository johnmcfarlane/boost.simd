// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor plus in scalar mode for bs::complex<double> type with no decorator (regular call).
#include <simd_bench.hpp>
#include <complex>

struct plus_std
{
  template < typename T>
  BOOST_FORCEINLINE std::complex<T> operator()(const std::complex<T> & a0,
                             const std::complex<T> & a1) const BOOST_NOEXCEPT
  {
    return a0+a1;
  }
};
namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_BENCH_MAIN()
{
  using T = std::complex<float>;
  run<T>(plus_std(), nsbg::rand<T>(-10, 10), nsbg::rand<T>(-10, 10));
}
