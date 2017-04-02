//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_SINH_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_SINH_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup group-complex-sinh  Complex sinh

    This function object computes the complex inverse hyperbolic tangent of z Branch cut exists outside
    the interval \f$[-1, +1]\f$ along the real axis.


    `complex<IEEEValue> sinh(complex<IEEEValue> const& z);`

    @par Header <boost/simd/type/complex/function/sinh.hpp>

    @par Notes

    - the complex inverse hyperbolic tangent of z is returned, in the range of
      a half-strip mathematically unbounded along the real axis and in the interval
      \f$[-i\pi/2, i\pi/2]\f$ along the imaginary axis.

    - take care that with non complex arguments, the real sinh function is called except if you prefix it by the `cmplx::`
      namespace (see example below).


    - Inverse hyperbolic tangent is a multivalued function and requires a branch cut on the complex plane.
      The branch cut is conventionally placed at the line segmentd \f$[-\infty, -1]\f$ and  \f$[1, \infty]\f$ of the real axis.


    - The mathematical definition of the principal value of inverse hyperbolic tangent is \f$ \frac12(\log(1+z)-\log(1-z)))\f$

    - `sinh(conj(z))` is always equal to `conj(sinh(z)`

    - `sinh(-z)` is always equal to `-sinh(z)`

    - limiting values

      We always have

      - If z is (+0,+0)}}, the result is (+0,+0)
      - If z is (NaN,NaN), the result is(NaN,NaN)
      - If z is (x,NaN) (for any finite positive  x), the result is(NaN,NaN)
      - If z is (x,\f$\infty\f$) (for any finite  positive x), the result is (NaN,NaN)
      - If z is (NaN,+y) (for any finite non-zero y), the result is(NaN,NaN)
      - If z is (\f$\infty\f$,y) (for any positive finite y), the result is (\f$\infty e^{iy}\f$\)

     And with pedantic_ decorator the remaining IEEE limits values are fulfilled

      - If z is (+0,\f$\infty\f$), the result is(\f$\pm0\f$, NaN) (the sign of the real part is unspecified)
      - If z is (+0,NaN), the result is(\f$\pm0\f$, NaN) (the sign of the real part is unspecified)
      - If z is (\f$\infty\f$,+0), the result is(\f$\infty\f$,+0)
      - If z is (\f$\infty, \infty\f$), the result is(\f$\pm\infty\f$,NaN) (the sign of the real part is unspecified)
      - If z is (\f$\infty\f$,NaN), the result is(\f$\pm\infty\f$,NaN) (the sign of the real part is unspecified)
      - If z is (NaN,+0), the result is(NaN,+0)

    @par Example:

       @snippet c_sinh.cpp sinh

    @par Possible output:

       @snippet c_sinh.txt sinh

  **/
  complex<IEEEValue> sinh(complex<IEEEValue> const& z);
} } }


#endif
#include <boost/simd/function/sinh.hpp>
#include <boost/simd/type/complex/function/impl/sinh.hpp>

#endif
