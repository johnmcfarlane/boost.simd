//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ATANH_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ATANH_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup group-complex-atanh  Complex atanh

    This function object computes the complex inverse hyperbolic tangent of z Branch cut exists outside
    the interval \f$[-1, +1]\f$ along the real axis.


    `complex<IEEEValue> atanh(complex<IEEEValue> const& z);`

    @par Header <boost/simd/type/complex/function/atanh.hpp>

    @par Notes

    - the complex inverse hyperbolic tangent of z is returned, in the range of
      a half-strip mathematically unbounded along the real axis and in the interval
      \f$[-i\pi/2, i\pi/2]\f$ along the imaginary axis.

    - take care that with non complex arguments, the real atanh function is called except if you prefix it by the `cmplx::`
      namespace (see example below).


    - Inverse hyperbolic tangent is a multivalued function and requires a branch cut on the complex plane.
      The branch cut is conventionally placed at the line segmentd \f$[-\infty, -1]\f$ and  \f$[1, \infty]\f$ of the real axis.


    - The mathematical definition of the principal value of inverse hyperbolic tangent is \f$ \frac12(\log(1+z)-\log(1-z)))\f$

    - `atanh(conj(z))` is always equal to `conj(atanh(z)`

    - `atanh(-z)` is always equal to `-atanh(z)`

    - limiting values

        - If z is (+0,+0), the result is (+0,+0)
        - If z is (+0,NaN), the result is (+0,NaN)
        - If z is (+1,+0), the result is (\f$\infty\f$,+0)
        - If z is (x,\f$\infty\f$) (for any finite positive x), the result is (0,\f$\pi/2\f$)
        - If z is (x,NaN) (for any finite nonzero x), the result is (NaN,NaN)
        - If z is (\f$\infty\f$,y) (for any finite positive y), the result is (0,\f$\pi/2\f$)
        - If z is (\f$\infty\f$,\f$\infty\f$), the result is (0,\f$\pi/2\f$)
        - If z is (\f$\infty\f$,NaN), the result is (+0,NaN)
        - If z is (NaN,y) (for any finite y), the result is {{tt|(NaN,NaN)
        - If z is (NaN,\f$\infty\f$), the result is (\f$\pm0, \pi/2\f$) (the sign of the real part is unspecified)
        - If z is (NaN,NaN), the result is (NaN,NaN)

    @par Example:

       @snippet c_atanh.cpp atanh

    @par Possible output:

       @snippet c_atanh.txt atanh

  **/
  complex<IEEEValue> atanh(complex<IEEEValue> const& z);
} } }


#endif

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, cmplx_atanh_, boost::dispatch::elementwise_<cmplx_atanh_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, cmplx_atanh_)
  }

  namespace cmplx
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::cmplx_atanh_,atanh);
  }
} }

#include <boost/simd/function/atanh.hpp>
#include <boost/simd/type/complex/function/impl/atanh.hpp>

#endif
