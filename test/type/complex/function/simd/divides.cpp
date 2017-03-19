//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex.hpp>
#include <boost/simd/type/complex/function/abs.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;


STF_CASE_TPL( "Divides with complex<T>/pack<T>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using c_t  = bs::complex<T>;
  using pc_t = bs::complex<p_t>;

  c_t r0(4,0), r1(0,2), r2(4,2);
  p_t v{3,-2,3,1};

  STF_ULP_EQUAL(r0 / v , (pc_t{ p_t(1.3333333333333333, -2, 1.3333333333333333, 4), p_t(0,0,0,0) }), 0.5);
  STF_ULP_EQUAL(r1 / v , (pc_t{ p_t(0), p_t(0.66666666666666666, -1, 0.666666666666666666, 2) }), 0.5);
  STF_ULP_EQUAL(r2 / v , (pc_t{ p_t(1.3333333333333333, -2, 1.3333333333333333, 4), p_t(0.66666666666666666, -1, 0.66666666666666666, 2) }), 0.5);
  STF_ULP_EQUAL(v  / r1, (pc_t{ p_t(0), p_t(-1.5, 1, -1.5, -0.5) }), 0.5);
  STF_ULP_EQUAL(v  / r0, (pc_t{ p_t(0.75000,  -0.50000,   0.75000,   0.25000), p_t(0,0,0,0) }), 0.5);
  STF_ULP_EQUAL(v  / r2, (pc_t{ p_t(0.60000,  -0.40000,   0.60000,   0.20000), p_t(-0.30000,   0.20000,  -0.30000,  -0.10000) }), 0.5);
}

STF_CASE_TPL( "Divides with to complex<pack<T>>/complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pc_t = bs::complex<p_t>;

  p_t   r1(1,2,3,4), r2(4, 3, 2, 1), r3(5,6,7,8);

  pc_t c2{ p_t(0.52941176470588235294117647058824,
               1.3846153846153846153846153846154,
               2.0769230769230769230769230769231,
               2.1176470588235294117647058823529),
      p_t(1.1176470588235294117647058823529,
          1.0769230769230769230769230769231,
          0.38461538461538461538461538461538,
          -0.47058823529411764705882352941176)
      };
  pc_t  c0(r1, r3), c1(r2, r1);
  STF_ULP_EQUAL(c0 / c1, c2, 0.5);
}

STF_CASE_TPL( "Divides with to complex<pack<T>>/pack<T>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pc_t = bs::complex<p_t>;

  p_t   r1(1,2,3,4), r2(4, 3, 2, 1), r3(5,6,7,8);
  pc_t  c0(r1, r3), c3(p_t(0.25,   2.0/3,   1.5,   4.0), p_t(1.25,   2.0,   3.5,   8.0));

  STF_EQUAL(c0/r2 , c3);

}

STF_CASE_TPL( "Divides with to complex<pack<T>>/complex<T>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using c_t  = bs::complex<T>;
  using pc_t = bs::complex<p_t>;
  p_t   r3(3, 6, 9, 12), i3(12, 9, 6, 3);
  c_t   i(1,3);
  pc_t  c1(r3, i3), c2(p_t(3.9000,   3.3000,   2.7000,   2.1000), p_t(0.30000,  -0.90000,  -2.10000,  -3.30000));

  STF_ULP_EQUAL(c1 / i, c2, 0.5);
}

STF_CASE_TPL( "Divides with to complex<pack<T>>/T", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pc_t = bs::complex<p_t>;

  p_t   r(1,2,3,4), i(4, 3, 2, 1);
  p_t   r3(3, 6, 9, 12), i3(12, 9, 6, 3);
  p_t   r4(0.176470588235294,   0.461538461538462,   0.692307692307692,   0.705882352941177),
    i4(-0.705882352941177,  -0.692307692307692,  -0.461538461538462,  -0.176470588235294);
  pc_t  c0(r,i), c1(r3, i3), c2(r4, i4);

  STF_ULP_EQUAL(c1 / 3  , c0, 0.5);
  STF_ULP_EQUAL(3 / c0 , c2,  4);
}
