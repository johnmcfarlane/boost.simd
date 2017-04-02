//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_PROJ_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_PROJ_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup group-complex-mul_i  Complex mul_i

    This function object returns the projection of the complex number z onto the Riemann sphere.

    For most z, `proj(z)==z`, but all complex infinities, even the numbers
    where one component is infinite and the other is NaN,
    become positive real infinity, (\f$\infty\f$, 0) or (\f$\infty\f$, -0).
    The sign of the imaginary (zero) component is the sign of imag(z).

    `complex<IEEEValue> proj(complex<IEEEValue> const& z);`

    @par Header <boost/simd/type/complex/function/proj.hpp>


    @par Example:

       @snippet c_proj.cpp proj

    @par Possible output:

       @snippet c_proj.txt proj

  **/
  complex<IEEEValue> proj(complex<IEEEValue> const& z);
} } }
#end

#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, proj_, boost::dispatch::elementwise_<proj_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, proj_)
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::proj_, proj);
} }

#include <boost/simd/type/complex/function/impl/proj.hpp>

#endif
