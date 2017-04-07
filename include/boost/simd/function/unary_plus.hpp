//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_UNARY_PLUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_UNARY_PLUS_HPP_INCLUDED

  /*!
    @ingroup group-operator
    @defgroup real-unary_plus unary_plus (function object)

    This function object returns the elementwise unary plus of the parameter

    Infix notation can be used with operator '+'

    @headerref{<boost/simd/function/unary_plus.hpp>}

    @par Description

      @code
      Value unary_plus(Value const& x);
      @endcode

    @par Note:

    - `r = unary_plus(x)` is equivalent to  `r = +x` for SIMD types.

    @see ( %real ) [plus](@ref real-plus), [unary_minus](@ref real-unary_minus)

    @par Example:

      @snippet unary_plus.cpp unary_plus

    @par Possible output:

      @snippet unary_plus.txt unary_plus

  **/

#include <boost/simd/function/scalar/unary_plus.hpp>
#include <boost/simd/function/simd/unary_plus.hpp>

#endif
