//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ACOS_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ACOS_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-acos acos (object function)

    This function object computes complex arc cosine of a complex value z. Branch cut exists outside
    the interval \f$[-1, +1]\f$ along the real axis.


    @par Description

    @code
    complex<IEEEValue> acos(complex<IEEEValue> const& z);
    @endcode

    @par Header <boost/simd/type/complex/function/acos.hpp>

    @par Notes

    - take care that with non complex arguments, the real acos function is called except if you prefix it by the `cmplx::`
      namespace (see example below).

    - f no errors occur, complex arc cosine of {z is returned, in the range \f$]0, \infty, ]\f$ along the real axis
      and in the range \f$]-i\pi, i\pi, ]\f$ along the imaginary axis.

    - inverse cosine (or arc cosine) is a multivalued function and requires a branch cut on the complex plane.
      The branch cut is conventionally placed at the line segments  \f$[-\infty, +1]\f$ and  \f$[1, \infty]\f$ of the real axis.

    - The mathematical definition of the principal value of arc sine is \f$\frac{\pi}2 + i \log(iz+\sqrt{1-z^2})\f$

    - `acos(conj(z))` is always equal to `conj(acos(z))`

    - we always have:

        - If z is (\f$\pm0,+0\f$), the result is (\f$\frac{\pi}2, -0\f$)
        - If z is (\f$\pm0\f$,NaN), the result is  (\f$\frac{\pi}2\f$, NaN)
        - If z is (x,\f$\infty\f$) (for any finite x), the result is (\f$\pi/2,-\infty\f$)
        - If z is (x,NaN)) (for any nonzero finite x), the result is (NaN,NaN))
        - If z is (\f$-\infty\f$,y) (for any positive finite y), the result is (\f$\pi,-\infty\f$)
        - If z is (\f$\infty\f$,y) (for any positive finite y), the result is (\f$+0,-\infty\f$)
        - If z is (\f$-\infty,\infty\f$), the result is (\f$3\pi/4,-\infty\f$)
        - If z is (\f$+\infty,\infty\f$), the result is (\f$\pi/4,-\infty\f$)
        - If z is (\f$\pm\infty\f$,NaN), the result is (NaN,\f$\pm\infty\f$) (the sign of the imaginary part is unspecified)
        - If z is (NaN,y) (for any finite y), the result is (NaN,NaN))
        - If z is (NaN,\f$\infty\f$), the result is (NaN,\f$-\infty\f$)
        - If z is (NaN,NaN), the result is (NaN,NaN))

    @see (real) acos

    @par Example:

       @snippet c_acos.cpp acos

    @par Possible output:

       @snippet c_acos.txt acos

  **/
} }


#endif

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, cmplx_acos_, boost::dispatch::elementwise_<cmplx_acos_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, cmplx_acos_)
  }

  namespace cmplx
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::cmplx_acos_,acos);
  }
} }

#include <boost/simd/function/acos.hpp>
#include <boost/simd/type/complex/function/impl/acos.hpp>

#endif
