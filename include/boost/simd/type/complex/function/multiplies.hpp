//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_MULTIPLIES_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_MULTIPLIES_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-multiplies multiplies (function object)

    This function object implements the binary product operator for complex arithmetic
    and for mixed complex/real arithmetic. Real arguments are treated as complex numbers
    with the real part equal to the argument and the imaginary part set to zero
    with possible optimization of the computations.

    @headerref{<boost/simd/type/complex/function/multiplies.hpp>}

    @par Description

    @code
    complex<IEEEValue> multiplies(complex<IEEEValue> const& z1, complex<IEEEValue> const& z2);
    @endcode



    @see ( %real ) multiplies

    @par Example:

       @snippet c_multiplies.cpp multiplies

    @par Possible output:

       @snippet c_multiplies.txt multiplies

  **/
  complex<IEEEValue> multiplies(complex<IEEEValue> const& z1, complex<IEEEValue> const& z2);
} } }
#endif

#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/type/complex/function/impl/multiplies.hpp>

#endif
