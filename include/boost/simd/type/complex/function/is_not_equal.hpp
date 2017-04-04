//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IS_NOT_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IS_NOT_EQUAL_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-is_not_equal is_not_equal (function object)

    This function object returns True if and only if real or imaginary part
    of the parameters are not equal.

    @headerref{<boost/simd/type/complex/function/is_not_equal.hpp>}

    @par Description

    @code
    as_logical<IEEEValue> is_not_equal(complex<IEEEValue> const& z1, complex<IEEEValue> const& z2);
    @endcode


    @see ( %real ) is_not_equal

    @par Example:

       @snippet c_is_not_equal.cpp is_not_equal

    @par Possible output:

       @snippet c_is_not_equal.txt is_not_equal

  **/
} }
#endif
#include <boost/simd/function/is_not_equal.hpp>
#include <boost/simd/type/complex/function/impl/is_not_equal.hpp>

#endif
