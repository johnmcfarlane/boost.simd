//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ATAN_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ATAN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-atan atan (object function)

    This function object computes complex arc tangent of a complex value z.
    Branch cut exists outside the interval [-i ; +i] along the imaginary axis.

    @par Description

    @code
    complex<IEEEValue> atan(complex<IEEEValue> const& z);
    @endcode

    @par Header <boost/simd/type/complex/function/atan.hpp>

    @par Notes

    - take care that with non complex arguments, the real atan function is called except if you prefix it by the `cmplx::`
      namespace (see example below).

    - Special cases are handled as if the operation is implemented by `-i*bs::atanh(i*z)`, where i is the imaginary unit.

    - inverse sine (or arc sine) is a multivalued function and requires a branch cut on the complex plane.
      The branch cut is conventionally placed at the line segments  \f$[-\infty, -1]\f$ and  \f$[1, \infty]\f$ of the real axis.

    - The mathematical definition of the principal value of inverse tangent is \f$ \frac12 i (\log(1-iz)-\log(1+iz)))\f$

    @see (real) atan

    @par Example:

       @snippet c_atan.cpp atan

    @par Possible output:

       @snippet c_atan.txt atan

  **/
  complex<IEEEValue> atan(complex<IEEEValue> const& z);
} } }


#endif

#include <boost/simd/function/atan.hpp>
#include <boost/simd/type/complex/function/impl/atan.hpp>

#endif
