//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_EXP_IPI_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_EXP_IPI_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/function/make_callable.hpp>
#include <boost/simd/detail/dispatch/hierarchy/functions.hpp>
#include <boost/simd/detail/dispatch.hpp>
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-exp_ipi exp_ipi (object function)

    This function object computes \f$ e^{i\pi z}\f$


    @par Description

    @code
    complex<IEEEValue> exp_ipi(complex<IEEEValue> const& z);
    @endcode

    @par Header <boost/simd/type/complex/function/exp_ipi.hpp>


    @see (real) exp_ipi

    @par Example:

       @snippet c_exp_ipi.cpp exp_ipi

    @par Possible output:

       @snippet c_exp_ipi.txt exp_ipi

  **/
  complex<IEEEValue> exp_ipi(complex<IEEEValue> const& z);
} } }


#endif
namespace boost { namespace simd
{
  namespace tag
  {
    BOOST_DISPATCH_MAKE_TAG(ext, exp_ipi_, boost::dispatch::elementwise_<exp_ipi_>);
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag, exp_ipi_)
  }

  BOOST_DISPATCH_CALLABLE_DEFINITION(tag::exp_ipi_, exp_ipi);
} }

#include <boost/simd/type/complex/function/impl/exp_ipi.hpp>

#endif
