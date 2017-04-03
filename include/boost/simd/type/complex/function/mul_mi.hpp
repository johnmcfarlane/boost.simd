//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_MUL_MI_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_MUL_MI_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-mul_mi mul_mi (object function)

    This function object returns the input  the parameter multiplied by -i (with \f$i^2 = -1\f$).

    @par Description

    @code
    complex<IEEEValue> mul_mi(complex<IEEEValue> const& z);
    @endcode

    @par Header <boost/simd/type/complex/function/mul_mi.hpp>


    @see (real) mul_mi

    @par Example:

       @snippet c_mul_mi.cpp mul_mi

    @par Possible output:

       @snippet c_mul_mi.txt mul_mi

  **/
  complex<IEEEValue> mul_mi(complex<IEEEValue> const& z1);
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
    BOOST_DISPATCH_MAKE_TAG(ext, mul_mi_, boost::dispatch::elementwise_<mul_mi_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, mul_mi_)
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::mul_mi_, mul_mi);
} }

#include <boost/simd/type/complex/function/impl/mul_mi.hpp>

#endif
