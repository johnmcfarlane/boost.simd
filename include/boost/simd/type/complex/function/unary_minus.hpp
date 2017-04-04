//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_UNARY_MINUS_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_UNARY_MINUS_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-unary_minus unary_minus (object function)

    This function object computes the unary minus of its complex parameter by reversing
    the sign of the real and imaginary parts.
    Infix notation can be used with operator '-'

    @par Description

    @code
    IEEEValue unary_minus(complex<IEEEValue> const& z);
    @endcode

    @par Header <boost/simd/type/complex/function/unary_minus.hpp>

    @see (real) unary_minus

    @par Example:

       @snippet c_unary_minus.cpp unary_minus

    @par Possible output:

       @snippet c_unary_minus.txt unary_minus

  **/
} }
#endif
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/type/complex/function/impl/unary_minus.hpp>

#endif
