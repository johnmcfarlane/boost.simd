//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_PLUS_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_PLUS_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-plus plus (function object)

    This function object implements the binary addition  operator for complex arithmetic
    and for mixed complex/real arithmetic. Real arguments are treated as complex numbers
    with the real part equal to the argument and the imaginary part set to zero
    with possible optimization of the computations.

    @headerref{<boost/simd/type/complex/function/plus.hpp>}

    @par Description

    @code
    complex<IEEEValue> plus(complex<IEEEValue> const& z1, complex<IEEEValue> const& z2);
    @endcode



    @see ( %real ) [plus](@ref  real-plus)

    @par Example:

       @snippet c_plus.cpp plus

    @par Possible output:

       @snippet c_plus.txt plus

  **/
  complex<IEEEValue> plus(complex<IEEEValue> const& z1, complex<IEEEValue> const& z2);
} } }
#endif

#include <boost/simd/function/plus.hpp>
#include <boost/simd/type/complex/function/impl/plus.hpp>

#endif
