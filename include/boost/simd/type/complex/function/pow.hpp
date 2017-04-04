//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_POW_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_POW_HPP_INCLUDED
#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-pow pow (function object)

    This function object computes complex x raised to a complex power y

    @headerref{<boost/simd/type/complex/function/pow.hpp>}

    @par Description

    @code
    IEEEValue pow(complex<IEEEValue> const& x, complex<IEEEValue> const& y);
    @endcode


    @par Notes

    - take care that with non complex arguments, the real pow function is called except if you prefix it by the `cmplx::`
      namespace (see example below).

    - The function have a branch cut along the negative real axis for the first argument.

    - by choice pow(0, 0) return 1.

    @see ( %real ) pow

     @par Example:

       @snippet c_pow.cpp pow

    @par Possible output:

       @snippet c_pow.txt pow

  **/
} }
#endif

namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, cmplx_pow_, boost::dispatch::elementwise_<cmplx_pow_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, cmplx_pow_)
  }

  namespace cmplx
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::cmplx_pow_,pow);
  }
} }

#include <boost/simd/function/pow.hpp>
#include <boost/simd/type/complex/function/impl/pow.hpp>

#endif
