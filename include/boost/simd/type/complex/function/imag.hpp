//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMAG_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IMAG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-imag imag (object function)

    This function object computes the imaginary part of the parameter.

    @par Description

    @code
    IEEEValue imag(complex<IEEEValue> const& z);
    @endcode

    @par Header <boost/simd/type/complex/function/imag.hpp>

    @see (real) imag

    @par Example:

       @snippet c_imag.cpp imag

    @par Possible output:

       @snippet c_imag.txt imag

  **/
  IEEEValue boost::simd::imag(complex<IEEEValue> const& z);
} }
#endif

#include <boost/simd/function/imag.hpp>
#include <boost/simd/type/complex/function/impl/imag.hpp>

#endif
