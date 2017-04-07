//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IMAG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IMAG_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-imag imag (function object)

    This function object returns the imaginary part of the parameter.
    for real types it is always 0.

    @headerref{<boost/simd/function/imag.hpp>}

    @par Description

      @code
      Value imag(Value const& x);
      @endcode

    @see ( %real ) [real](@ref real-real)

    @par Example:

      @snippet imag.cpp imag

    @par Possible output:

      @snippet imag.txt imag

  **/

#include <boost/simd/function/scalar/imag.hpp>
#include <boost/simd/function/simd/imag.hpp>

#endif
