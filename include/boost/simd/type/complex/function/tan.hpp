//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_TAN_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_TAN_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-tan tan (function object)

    This function object computes complex tangent of a complex value z.

    @headerref{<boost/simd/type/complex/function/tan.hpp>}

    @par Description

    @code
    IEEEValue tan(complex<IEEEValue> const& z);
    @endcode


    @par Notes

      - Errors and special cases are handled as if the operation is
        implemented by `-i * std::tanh(i*z)`, where i is the imaginary unit.

      - Mathematical definition of the tangent is \f$ i\frac{e^{-iz}-e^{iz}}{e^{-i}z+e^{iz}}\f$

    @see ( %real ) tan

    @par Example:

       @snippet c_tan.cpp tan

    @par Possible output:

       @snippet c_tan.txt tan

  **/
} }
#endif

#include <boost/simd/function/tan.hpp>
#include <boost/simd/type/complex/function/impl/tan.hpp>

#endif
