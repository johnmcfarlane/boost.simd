//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ACOSH_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ACOSH_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx

  /*!
    @ingroup group-complex
    @defgroup complex-acosh acosh (function object)

    This function object computes complex hyperbolic cosine of a complex value z.

    @headerref{<boost/simd/type/complex/function/acosh.hpp>}

    @par Description

    @code
    IEEEValue acosh(complex<IEEEValue> const& z);
    @endcode


    @par Notes

     - take care that with non complex arguments, the real acos function is called except if you prefix it by the `cmplx::`
       namespace (see example below).

     -  `acosh(conj(z))` is always equal to `conj(acosh(z))`

     - limiting values

         - If z is (\f$\pm0\f$,+0), the result is (+0,\f$\pi/2\f$)
         - If z is (x,\f$\infty\f$) (for any finite x), the result is (\f$\infty\f$,\f$\pi/2\f$)
         - If z is (x,NaN) (for any finite non zero x), the result is (NaN,NaN)
         - If z is (0,NaN) , the result is (NaN,\f$\pi/2\f$)
         - If z is (\f$-\infty\f$,y) (for any positive finite y), the result is (\f$\infty\f$,\f$\pi\f$)
         - If z is (\f$\infty\f$,y) (for any positive finite y), the result is (\f$\infty\f$,+0)
         - If z is (\f$-\infty\f$,\f$\infty\f$), the result is (\f$\infty\f$,\f$3\pi/4\f$)
         - If z is (\f$\pm\infty\f$,NaN), the result is (\f$\infty\f$,NaN)
         - If z is (NaN,y) (for any finite y), the result is (NaN,NaN) and FE_INVALID may be raised.
         - If z is (NaN,\f$\infty\f$), the result is (\f$\infty\f$,NaN)
         - If z is (NaN,NaN), the result is (NaN,NaN)


     - The mathematical definition of the principal value of the inverse hyperbolic cosine is \f$\log(z + \sqrt{z+1} \sqrt{z-1})\f$

    @see ( %real ) acosh

    @par Example:

       @snippet c_acosh.cpp acosh

    @par Possible output:

       @snippet c_acosh.txt acosh

  **/
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
    BOOST_DISPATCH_MAKE_TAG(ext, cmplx_acosh_, boost::dispatch::elementwise_<cmplx_acosh_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, cmplx_acosh_)
  }

  namespace cmplx
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::cmplx_acosh_,acosh);
  }
} }

#include <boost/simd/function/acosh.hpp>
#include <boost/simd/type/complex/function/impl/acosh.hpp>

#endif
