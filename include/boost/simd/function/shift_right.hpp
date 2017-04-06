//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHIFT_RIGHT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHIFT_RIGHT_HPP_INCLUDED

  /*!
    @ingroup group-operator
    @defgroup real-shift_right shift_right (function object)

    This function object returns the first operand shifted right by the second one

    Infix notation can be used with operator '>>'

    @headerref{<boost/simd/function/shift_right.hpp>}

    @par Description

      @code
      Value shift_right(Value const& x, IntegerValue const& n);
      @endcode

    @par Note:
      - on many architectures a scalar second parameter results in a much faster call

    @see  shift_left, shr, rshl, rshr, rol, ror
    @par Example:

      @snippet shift_right.cpp shift_right

    @par Possible output:

      @snippet shift_right.txt shift_right

  **/

#include <boost/simd/function/scalar/shift_right.hpp>
#include <boost/simd/function/simd/shift_right.hpp>

#endif
