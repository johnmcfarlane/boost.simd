// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------


/// bench for functor cos in scalar mode for float type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/cos.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

struct cos_bench
{
  template < class T >
  BOOST_FORCEINLINE bs::complex<T> operator()(const T & r, const T & i) const BOOST_NOEXCEPT
  {
    bs::complex<T> z{r, i};
    return bs::cos(z);
  }
};

DEFINE_SCALAR_BENCH(scalar_cos, cos_bench());

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_cos, float>(-10, 10, -10, 10);
}

