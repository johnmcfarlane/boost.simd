//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_SQR_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_SQR_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-sqr sqr (function object)

    This function object returns the square of the input.

    @headerref{<boost/simd/type/complex/function/sqr.hpp>}

    @par Description

    @code
    complex<IEEEValue> sqr(complex<IEEEValue> const& z);
    @endcode



    @see ( %real ) [sqr](@ref  real-sqr)

    @par Example:

       @snippet c_sqr.cpp sqr

    @par Possible output:

       @snippet c_sqr.txt sqr

  **/
  complex<IEEEValue> sqr(complex<IEEEValue> const& z1);
} } }
#endif
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/type/complex/function/impl/sqr.hpp>

#endif
