//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IS_INVALID_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IS_INVALID_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup group-complex-is_invalid  Complex is_invalid

    This function object returns True if and only if real or imaginary part
    of the parameters is invalid.

    `as_logical<IEEEValue> is_invalid(complex<IEEEValue> const& z);`

    @par Header <boost/simd/type/complex/function/is_invalid.hpp>

    @par Example:

       @snippet c_is_invalid.cpp is_invalid

    @par Possible output:

       @snippet c_is_invalid.txt is_invalid

  **/
  as_logical<IEEEValue> boost::simd::is_invalid(complex<IEEEValue);
} }
#endif
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/type/complex/function/impl/is_invalid.hpp>

#endif
