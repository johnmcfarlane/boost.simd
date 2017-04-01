//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_COSH_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_COSH_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup group-complex-cosh  Complex cosh

    This function object computes the complex inverse hyperbolic tangent of z Branch cut exists outside
    the interval \f$[-1, +1]\f$ along the real axis.


    `complex<IEEEValue> cosh(complex<IEEEValue> const& z);`

    @par Header <boost/simd/type/complex/function/cosh.hpp>

    @par Notes

    - the complex inverse hyperbolic tangent of z is returned, in the range of
      a half-strip mathematically unbounded along the real axis and in the interval
      \f$[-i\pi/2, i\pi/2]\f$ along the imaginary axis.

    - take care that with non complex arguments, the real cosh function is called except if you prefix it by the `cmplx::`
      namespace (see example below).


    - Inverse hyperbolic tangent is a multivalued function and requires a branch cut on the complex plane.
      The branch cut is conventionally placed at the line segmentd \f$[-\infty, -1]\f$ and  \f$[1, \infty]\f$ of the real axis.


    - The mathematical definition of the principal value of inverse hyperbolic tangent is \f$ \frac12(\log(1+z)-\log(1-z)))\f$

    - `cosh(conj(z))` is always equal to `conj(cosh(z)`

    - `cosh(-z)` is always equal to `cosh(z)`

    - limiting values

      - If z is (+0,+0)}}, the result is (1,+0)
      - If z is (+0,\f$\infty\f$), the result is(NaN,\f$\pm0\f$) (the sign of the imaginary part is unspecified)
      - If z is (+0,NaN), the result is(NaN,\f$\pm0\f$) (the sign of the imaginary part is unspecified)
      - If z is (x,\f$\infty\f$) (for any finite non-zero x), the result is (NaN,NaN)
      - If z is (x,NaN) (for any finite non-zero x), the result is(NaN,NaN)
      - If z is (\f$\infty\f$,+0), the result is(+∞,+0)
      - If z is (\f$\infty\f$,y) (for any finite non-zero y), the result is (\f$\infty e^{iy}\f$\)
      - If z is (\f$\infty, \infty\f$), the result is(\f$\pm\infty\f$,NaN) (the sign of the real part is unspecified)
      - If z is (\f$\infty\f$,NaN), the result is(\f$\infty\f$,NaN)
      - If z is (NaN,+0), the result is(NaN, \f$\pm0\f$) (the sign of the imaginary part is unspecified)
      - If z is (NaN,+y) (for any finite non-zero y), the result is(NaN,NaN)
      - If z is (NaN,NaN), the result is(NaN,NaN)

    @par Example:

       @snippet c_cosh.cpp cosh

    @par Possible output:

       @snippet c_cosh.txt cosh

  **/
  complex<IEEEValue> cosh(complex<IEEEValue> const& z);
} } }


#endif

#include <boost/simd/function/cosh.hpp>
#include <boost/simd/type/complex/function/impl/cosh.hpp>

#endif
