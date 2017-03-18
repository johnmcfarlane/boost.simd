// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor sinh in scalar mode for bs::complex<float> type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/type/complex/function/sinh.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_BENCH_MAIN()
{
  using T = bs::complex<float>;
  run<T>(bs::sinh, nsbg::rand<T>(-10, 10));
}
