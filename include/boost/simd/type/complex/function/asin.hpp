//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ASIN_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ASIN_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-asin asin (function object)

    This function object computes complex arc sine of a complex value z. Branch cut exists outside
    the interval \f$[-1, +1]\f$ along the real axis.


    @headerref{<boost/simd/type/complex/function/asin.hpp>}

    @par Description

    @code
    complex<IEEEValue> asin(complex<IEEEValue> const& z);
    @endcode


    @par Notes

    - take care that with non complex arguments, the real asin function is called except if you prefix it by the `cmplx::`
      namespace (see example below).

    - For any z, asin(z) = acos(-z) - \f$\pi/2\f$ (see [acos](@ref complex-acos) for limit cases detail)

    - inverse sine (or arc sine) is a multivalued function and requires a branch cut on the complex plane.
      The branch cut is conventionally placed at the line segments  \f$[-\infty, +1]\f$ and  \f$[1, \infty]\f$ of the real axis.

    - The mathematical definition of the principal value of arc sine is \f$-i \log(iz+\sqrt{1-z^2})\f$

    @see ( %real ) [asin](@ref  real-asin)

    @par Example:

       @snippet c_asin.cpp asin

    @par Possible output:

       @snippet c_asin.txt asin

  **/
  complex<IEEEValue> asin(complex<IEEEValue> const& z);
} } }


#endif

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, cmplx_asin_, boost::dispatch::elementwise_<cmplx_asin_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, cmplx_asin_)
  }

  namespace cmplx
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::cmplx_asin_,asin);
  }
} }

#include <boost/simd/function/asin.hpp>
#include <boost/simd/type/complex/function/impl/asin.hpp>

#endif
