//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_MINUS_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_MINUS_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-minus minus (object function)

    This function object implements the binary difference operator for complex arithmetic
    and for mixed complex/real arithmetic. Real arguments are treated as complex numbers
    with the real part equal to the argument and the imaginary part set to zero
    with possible optimization of the computations.

    @par Description

    @code
    complex<IEEEValue> minus(complex<IEEEValue> const& z1, complex<IEEEValue> const& z2);
    @endcode

    @par Header <boost/simd/type/complex/function/minus.hpp>


    @see (real) minus

    @par Example:

       @snippet c_minus.cpp minus

    @par Possible output:

       @snippet c_minus.txt minus

  **/
  complex<IEEEValue> minus(complex<IEEEValue> const& z1, complex<IEEEValue> const& z2);
} } }
#endif

#include <boost/simd/function/minus.hpp>
#include <boost/simd/type/complex/function/impl/minus.hpp>

#endif
