//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_LOG10_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_LOG10_HPP_INCLUDED
#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-log10 log10 (function object)

    This function object computes complex common (base 10) logarithm of a complex value z.

    @headerref{<boost/simd/type/complex/function/log10.hpp>}

    @par Description

    @code
    complex<IEEEValue> log10(complex<IEEEValue> const& z);
    @endcode


    @par Notes

      - take care that with non complex arguments, the real log function is called except if you prefix it by the `cmplx::`
        namespace (see example below).

      - The function is continuous onto the branch cut taking into account the sign of imaginary part

      - The function have  a branch cut along the negative real axis.

      - `log(std::conj(z))`is always equal to `conj(std::log(z))`

    @par Limits
      - we always have:

        - If z is (-0,+0), the result is (\f$-\infty, \pi\f$)
        - If z is (+0,+0), the result is (\f$-\infty\f$, +0)
        - If z is (x,\f$\infty\f$) (for any finite x), the result is (\f$-\infty, \pi/2\f$)
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


    @see pow, exp, log


    @see ( %real ) [log10](@ref  real-log10)

    @par Example:

       @snippet c_log10.cpp log10

    @par Possible output:

       @snippet c_log10.txt log10

  **/
} } }

#endif

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, cmplx_log10_, boost::dispatch::elementwise_<cmplx_log10_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, cmplx_log10_)
  }

  namespace cmplx
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::cmplx_log10_,log10);
  }
} }

#include <boost/simd/function/log10.hpp>
#include <boost/simd/type/complex/function/impl/log10.hpp>

#endif
