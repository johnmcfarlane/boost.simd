//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_POLAR_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_POLAR_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-polar polar (object function)

    This function object constructs a complex from its modulus and argument.

    @par Description

    @code
    complex<IEEEValue> polar(IEEEValue const& rho, IEEEValue const& theta);
    @endcode

    @par Header <boost/simd/type/complex/function/polar.hpp>


    @see (real) polar

    @par Example:

       @snippet c_polar.cpp polar

    @par Possible output:

       @snippet c_polar.txt polar

  **/
  complex<IEEEValue> polar(complex<IEEEValue> const& z1, complex<IEEEValue> const& z2);
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
    BOOST_DISPATCH_MAKE_TAG(ext, polar_, boost::dispatch::elementwise_<polar_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, polar_)
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::polar_, polar);
} }

#include <boost/simd/type/complex/function/impl/polar.hpp>

#endif
