//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_LOG_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_LOG_HPP_INCLUDED
#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup group-complex-log  Complex log

    This function object computes complex natural (base e) logarithm of a complex value z with a branch cut along the negative real axis.

    `complex<IEEEValue> log(complex<IEEEValue> const& z);`

    @par Header <boost/simd/type/complex/function/log.hpp>

    @par Notes

    - take care that with non complex arguments, the real log function is called except if you prefix it by the `cmplx::`
      namespace (see example below).

    - The function is continuous onto the branch cut taking into account the sign of imaginary part

    - `log(std::conj(z))`is always equal to `conj(std::log(z))`

    - we always have:

        - If z is (\f$-0,+0\f$), the result is (\f$-\infty, \pi\f$)
        - If z is (\f$+0,+0\f$), the result is (\f$-\infty\f$, +0)
        - If z is (x,\f$\infty\f$) (for any finite x), the result is (\f$-\infty, \frac{\pi}2\f$)
        - If z is (x,NaN) (for any finite x), the result is (NaN,NaN)
        - If z is (\f$-\infty\f$,y) (for any finite positive y), the result is (\f$-\infty\f$, \f$\pi\f$)
        - If z is (\f$\infty\f$,y) (for any finite positive y), the result is (\f$-\infty\f$, +0)
        - If z is (NaN,y) (for any finite y), the result is (NaN,NaN)
        - If z is (NaN,NaN), the result is (NaN,NaN)

    - and with the pedantic_ decorator:

        - If z is (\f$-\infty\f$,\f$\infty\f$), the result is (\f$\infty\f$, \f$3\pi/4\f$)
        - If z is (\f$\infty\f$,\f$\infty\f$), the result is (\f$\infty\f$, \f$\pi/4\f$)
        - If z is (\f$\pm\infty\f$,NaN), the result is (\f$\infty\f$,NaN)
        - If z is (NaN,\f$\infty\f$), the result is (\f$\infty\f$,NaN)
        - If z is (NaN,\f$\infty\f$), the result is (\f$\infty\f$,NaN)

    @par Example:

       @snippet c_log.cpp log

    @par Possible output:

       @snippet c_log.txt log

  **/
  complex<IEEEValue> log(complex<IEEEValue> const& z);
} } }


#endif

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, cmplx_log_, boost::dispatch::elementwise_<cmplx_log_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, cmplx_log_)
  }

  namespace cmplx
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::cmplx_log_,log);
  }
} }

#include <boost/simd/function/log.hpp>
#include <boost/simd/type/complex/function/impl/log.hpp>

#endif
