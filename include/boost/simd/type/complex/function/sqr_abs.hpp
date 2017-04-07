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
    @defgroup complex-sqr_abs sqr_abs (object function)

    This function object calculates the square of the modulus of the complex z

    headerref{<boost/simd/type/complex/function/sqr_abs.hpp>}

    @par Description

        @code
        IEEEValue sqr_abs(complex<IEEEValue> const& z);
        @endcode

    @par Notes

      - This function is a lot faster than complex [abs](@ref complex-abs) and is well
        suited for comparisons if overflow has no risk to occur.

    @see ( %real ) [abs](@ref  real-abs), [sqr_abs](@ref  real-sqr_abs),  ( %complex ) [abs](@ref complex-abs)

    @par Example:

       @snippet c_sqr_abs.cpp sqr_abs

    @par Possible output:

       @snippet c_sqr_abs.txt sqr_abs

  **/
} }
#endif

#include <boost/simd/function/sqr_abs.hpp>
#include <boost/simd/type/complex/function/impl/sqr_abs.hpp>

#endif
