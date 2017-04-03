//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IS_EQUAL_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-is_equal is_equal (object function)

    This function object returns True if and only if real and imaginary parts
    of the parameters are equal.

    @par Description

    @code
    as_logical<IEEEValue> is_equal(complex<IEEEValue> const& z1,complex<IEEEValue> const& z2);
    @endcode

    @par Header <boost/simd/type/complex/function/is_equal.hpp>

    @see (real) is_equal

    @par Example:

       @snippet c_is_equal.cpp is_equal

    @par Possible output:

       @snippet c_is_equal.txt is_equal

  **/
  as_logical<IEEEValue> boost::simd::is_equal(complex<IEEEValue> const& z1,complex<IEEEValue> const& z2);
} }
#endif

#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/type/complex/function/impl/is_equal.hpp>

#endif
