//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IS_EQUAL_HPP_INCLUDED
  /*!
    @ingroup group-complex
    @defgroup complex-is_equal is_equal (function object, complex version)

    This function object, complex version returns True if and only if real and imaginary parts
    of the parameters are equal.

    @headerref{<boost/simd/type/complex/function/is_equal.hpp>}

    @par Description

    @code
    as_logical<IEEEValue> is_equal(complex<IEEEValue> const& z1,complex<IEEEValue> const& z2);
    @endcode


    @see ( %real ) [is_equal](@ref  real-is_equal)

    @par Example:

       @snippet c_is_equal.cpp is_equal

    @par Possible output:

       @snippet c_is_equal.txt is_equal

  **/

#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/type/complex/function/impl/is_equal.hpp>

#endif
