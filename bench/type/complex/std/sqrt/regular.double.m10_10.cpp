// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor sqrt in std mode for double type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/sqrt.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_BENCH_MAIN()
{
  using T = std::complex<double>;
  run<T>(bs::std_(bs::sqrt), nsbg::rand<T>(-10, 10, -10, 10));
}

