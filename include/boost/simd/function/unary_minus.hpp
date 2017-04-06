//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_UNARY_MINUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_UNARY_MINUS_HPP_INCLUDED

  /*!
    @ingroup group-operator
    @defgroup real-unary_minus unary_minus (function object)

    This function object returns the elementwise unary minus of the parameter

    Infix notation can be used with operator '-'

    @headerref{<boost/simd/function/unary_minus.hpp>}

    @par Description

      @code
      Value unary_minus(Value const& x);
      @endcode

    @par Decorators
    - `saturated_` ensures that `saturated_(unary_minus)(Valmin<T>())` is `Valmin<T>()`

    @par Note:

    - `r = unary_minus(x)` is equivalent to  `r = -x` for SIMD types.

    @see  minus, unary_plus

    @par Example:

      @snippet unary_minus.cpp unary_minus

    @par Possible output:

      @snippet unary_minus.txt unary_minus

  **/

#include <boost/simd/function/scalar/unary_minus.hpp>
#include <boost/simd/function/simd/unary_minus.hpp>

#endif
