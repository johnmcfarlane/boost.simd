//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_MUL_I_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_MUL_I_HPP_INCLUDED

  /*!
    @ingroup group-complex
    @defgroup complex-mul_i mul_i (function object, complex version)

    This function object, complex version returns the input parameter multiplied by i (with \f$i^2 = -1\f$).

    @headerref{<boost/simd/type/complex/function/mul_i.hpp>}

    @par Description

    @code
    complex<IEEEValue> mul_i(complex<IEEEValue> const& z);
    @endcode

    @par Example:

       @snippet c_mul_i.cpp mul_i

    @par Possible output:

       @snippet c_mul_i.txt mul_i

  **/

#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, mul_i_, boost::dispatch::elementwise_<mul_i_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, mul_i_)
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::mul_i_, mul_i);
} }

#include <boost/simd/type/complex/function/impl/mul_i.hpp>

#endif
