//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ASINH_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ASINH_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx

  /*!
    @ingroup group-complex
    @defgroup complex-asinh asinh (function object)

    This function object computes complex hyperbolic cosine of a complex value z.

    @headerref{<boost/simd/type/complex/function/asinh.hpp>}

    @par Description

    @code
    IEEEValue asinh(complex<IEEEValue> const& z);
    @endcode


    @par Notes

     -  `asinh(conj(z))` is always equal to `conj(asinh(z))`

     -   `asinh(-z)` is always equal to `-asinh(z)`

     - limit values

        - If z is (+0,+0), the result is (+0,+0)
        - If z is (x,\f$\infty\f$) (for any positive finite x), the result is (\f$\infty\f$,\f$\pi/2\f$)
        - If z is (x,NaN) (for any finite x), the result is (NaN,NaN)
        - If z is (\f$\infty\f$,y) (for any positive finite y), the result is (\f$\infty\f$,+0)
        - If z is (\f$\infty\f$,\f$\infty\f$), the result is (\f$\infty\f$,\f$\pi/4\f$)
        - If z is (\f$\infty\f$,NaN), the result is (\f$\infty\f$,NaN)
        - If z is (NaN,+0), the result is (NaN,+0)
        - If z is (NaN,y) (for any finite nonzero y), the result is (NaN,NaN)
        - If z is (NaN,\f$\infty\f$), the result is (\f$\pm\infty\f$,NaN) (the sign of the real part is unspecified)
        - If z is (NaN,NaN), the result is (NaN,NaN)


     - Inverse hyperbolic sine is a multivalued function and requires a branch cut on the complex plane.
       The branch cut is conventionally placed at the line segments (-i\f$\infty\f$,-i) and (i,i\f$\infty\f$) of the imaginary axis.

     - The mathematical definition of the principal value of the inverse hyperbolic sine is  \f$\log(z + \sqrt{1+z^2}\f$

    @see ( %real ) asinh

    @par Example:

       @snippet c_asinh.cpp asinh

    @par Possible output:

       @snippet c_asinh.txt asinh

  **/
} } }
#endif

#include <boost/simd/function/asinh.hpp>
#include <boost/simd/type/complex/function/impl/asinh.hpp>

#endif
