//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_SQRT_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_SQRT_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-sqrt sqrt (object function)

    This function object computes complex square root of a complex value z.

    @par Description

    @code
    complex<IEEEValue> sqrt(complex<IEEEValue> const& z);
    @endcode

    @par Header <boost/simd/type/complex/function/sqrt.hpp>

    @par Notes

    - take care that with non complex arguments, the real sqrt function is called except if you prefix it by the `cmplx::`
      namespace (see example below).

    - if no errors occur, sqyare root is returned in the range of the right half-plane,
      including the imaginary axis \f$[0,-\infty]\f$ along the real axis and \f$[-\infty,\infty ]\f$ along the imaginary axis.)

    - If the argument is a negative real number, the result lies on the positive imaginary axis.

    - `bs::ssqrt(conj(z)) == conj(bs::sqrt(z))`

    - we always have:

        - If z is (\f$\pm0,\pm0\f$), the result is (\f$\pm0,\pm0\f$)
        - If z is (NaN,NaN), the result is (NaN,NaN)
        - If z is (\f$-\infty\f$, y), the result is (\f$0,\infty\f$) for finite positive y
        - If z is (\f$\infty\f$, y), the result is (\f$\infty\f$, 0) for finite positive y
        - If z is (\f$-\infty\f$, Nan), the result is (Nan, \f$\pm\infty\f$)  (sign of imaginary part unspecified)
        - If z is (\f$\infty\f$, Nan), the result is (\f$\infty\f$, Nan),
        - If z is (x, Nan), the result is (Nan, Nan), (unless x is \f$\pm\infty\f$)

     - and with the pedantic_ decorator:

        - If z is (Nan, y),  the result is (NaN,NaN)
        - If z is (x, \f$\infty\f$), the result is (\f$\infty, \infty\f$)

    @see (real) sqrt

    @par Example:

       @snippet c_sqrt.cpp sqrt

    @par Possible output:

       @snippet c_sqrt.txt sqrt

  **/
  complex<IEEEValue> sqrt(complex<IEEEValue> const& z);
} } }


#endif

#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, cmplx_sqrt_, boost::dispatch::elementwise_<cmplx_sqrt_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, cmplx_sqrt_)
  }

  namespace cmplx
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::cmplx_sqrt_,sqrt);
  }
} }

#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/type/complex/function/impl/sqrt.hpp>

#endif
