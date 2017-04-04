//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_CONJ_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_CONJ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-conj conj (function object)

    This function object computes the complex conjugate of z by reversing the sign of the imaginary part.

    @headerref{<boost/simd/type/complex/function/conj.hpp>}

    @par Description

    @code
    IEEEValue conj(complex<IEEEValue> const& z);
    @endcode


    @see ( %real ) conj

    @par Example:

       @snippet c_conj.cpp conj

    @par Possible output:

       @snippet c_conj.txt conj

  **/
} }
#endif

#include <boost/simd/function/conj.hpp>
#include <boost/simd/type/complex/function/impl/conj.hpp>

#endif
