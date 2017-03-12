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

STF_CASE_TPL( "Divides with complex<T>/complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(4,0), r1(0,4), r2(2,2);

  STF_EQUAL(r0 / r0, bs::complex<T>(1, 0));
  STF_EQUAL(r1 / r1, bs::complex<T>(1, 0));
  STF_EQUAL(r2 / r2, bs::complex<T>(1, 0));
  STF_EQUAL(r0 / r1, bs::complex<T>(0, -1));
  STF_EQUAL(r0 / r2, bs::complex<T>(1, -1));
  STF_EQUAL(r1 / r2, bs::complex<T>(1, 1));
}

STF_CASE_TPL( "Divides with complex<T>/T", STF_IEEE_TYPES)
{
  bs::complex<T> r0(6,0), r1(0,2), r2(2,2);

  STF_EQUAL(r0 / 3 , bs::complex<T>(2,0));
  STF_EQUAL(3  / r0, bs::complex<T>(0.5,0));
  STF_EQUAL(r1 / 3 , bs::complex<T>(0, 2.0/3.0));
  STF_EQUAL(3  / r1, bs::complex<T>(0, -1.5));
  STF_EQUAL(r2 / 2 , bs::complex<T>(1, 1));
  STF_EQUAL(4  / r2, bs::complex<T>(1, -1));
}

// STF_CASE_TPL( "Divides with complex<T>/pack<T>", STF_IEEE_TYPES)
// {
//   using p_t  = bs::pack<T,4>;
//   using c_t  = bs::complex<T>;
//   using pc_t = bs::complex<p_t>;

//   c_t r0(4,0), r1(0,2), r2(4,2);
//   p_t v{3,-2,0,1};

//   STF_EQUAL(r0 / v , (pc_t{ p_t(12, -8, 0, 4), p_t(0,0,0,0) }));
//   STF_EQUAL(v  / r0, (pc_t{ p_t(12, -8, 0, 4), p_t(0,0,0,0) }));
//   STF_EQUAL(r1 / v , (pc_t{ p_t(0), p_t(6, -4, 0, 2) }));
//   STF_EQUAL(v  / r1, (pc_t{ p_t(0), p_t(6, -4, 0, 2) }));
//   STF_EQUAL(r2 / v , (pc_t{ p_t(12, -8, 0, 4), p_t(6, -4, 0, 2) }));
//   STF_EQUAL(v  / r2, (pc_t{ p_t(12, -8, 0, 4), p_t(6, -4, 0, 2) }));
// }

STF_CASE_TPL( "Divides with to complex<pack<T>>/complex<pack<T>>", STF_IEEE_TYPES)
{
  using p_t  = bs::pack<T,4>;
  using pc_t = bs::complex<p_t>;

  p_t   r1(1,2,3,4), r2(4, 3, 2, 1), r3(5,6,7,8);
//   p_t   z1(0.529411764705882,   1.384615384615385,   2.076923076923077,   2.117647058823529),
//     z2(1.117647058823529,   1.076923076923077,   0.384615384615385,  -0.470588235294118);

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

// STF_CASE_TPL( "Divides with to complex<pack<T>>/complex<T>", STF_IEEE_TYPES)
// {
//   using p_t  = bs::pack<T,4>;
//   using c_t  = bs::complex<T>;
//   using pc_t = bs::complex<p_t>;
//   p_t   r3(3, 6, 9, 12), i3(12, 9, 6, 3);
//   p_t   r1(1, 2, 3, 4), i1(4, 3, 2, 1);
//   c_t   i(1,3);
//   pc_t  c1(r3, i3), c2(-i1, r1);

//   STF_EQUAL(c1 / i, c2);
// }

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
