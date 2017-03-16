// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor sqr_abs in std mode for float type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/sqr_abs.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

struct sqr_abs_std
{
  template < typename T >
  BOOST_FORCEINLINE T operator()(const std::complex<T> & a0) const
  {
    return std::norm(a0);
  }
};

DEFINE_BENCH_MAIN()
{
  using T = std::complex<float>;
  run<T>(sqr_abs_std(), nsbg::rand<T>(-10, 10, -10, 10));
}

