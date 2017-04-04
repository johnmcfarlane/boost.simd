//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_UNARY_PLUS_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_UNARY_PLUS_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-unary_plus unary_plus (object function)

    This function object computes the unary plus of its complex parameter
    (in fact acts as identity).
    Infix notation can be used with operator '-'

    @par Description

    @code
    IEEEValue unary_plus(complex<IEEEValue> const& z);
    @endcode

    @par Header <boost/simd/type/complex/function/unary_plus.hpp>

    @see (real) unary_plus

    @par Example:

       @snippet c_unary_plus.cpp unary_plus

    @par Possible output:

       @snippet c_unary_plus.txt unary_plus

  **/
} }
#endif
#include <boost/simd/function/unary_plus.hpp>
#include <boost/simd/type/complex/function/impl/unary_plus.hpp>

#endif
