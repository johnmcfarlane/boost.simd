//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_EXP_I_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_EXP_I_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-exp_i exp_i (function object)

    This function object computes \f$ e^{iz}\f$


    @headerref{<boost/simd/type/complex/function/exp_i.hpp>}

    @par Description

    @code
    complex<IEEEValue> exp_i(complex<IEEEValue> const& z);
    @endcode



    @see ( %real ) [exp_i](@ref  real-exp_i)

    @par Example:

       @snippet c_exp_i.cpp exp_i

    @par Possible output:

       @snippet c_exp_i.txt exp_i

  **/
  complex<IEEEValue> exp_i(complex<IEEEValue> const& z);
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
    BOOST_DISPATCH_MAKE_TAG(ext, exp_i_, boost::dispatch::elementwise_<exp_i_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, exp_i_)
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::exp_i_, exp_i);
} }

#include <boost/simd/type/complex/function/impl/exp_i.hpp>

#endif
