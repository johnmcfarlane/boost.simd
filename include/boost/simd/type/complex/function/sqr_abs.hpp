//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_SQR_ABS_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_SQR_ABS_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup group-complex-sqr_abs  Complex sqr_abs

    This function object calculates the square of the modulus of the complex z

    `IEEEValue sqr_abs(complex<IEEEValue> const& z);`

    @par Header <boost/simd/type/complex/function/sqr_abs.hpp>

    @par Notes

      - This function is a lot faster than @ref "Complex abs" abs  and is well suited for comparisons if overflow
        has no risk to occur.
    @par Example:

       @snippet c_sqr_abs.cpp sqr_abs

    @par Possible output:

       @snippet c_sqr_abs.txt sqr_abs

  **/
  IEEEValue boost::simd::sqr_abs(complex<IEEEValue> const& z);
} }
#endif

#include <boost/simd/function/sqr_abs.hpp>
#include <boost/simd/type/complex/function/impl/sqr_abs.hpp>

#endif
