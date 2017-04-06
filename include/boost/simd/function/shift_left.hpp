//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHIFT_LEFT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHIFT_LEFT_HPP_INCLUDED

  /*!
    @ingroup group-operator
    @defgroup real-shift_left shift_left (function object)

    This function object returns the first parameter shifted left by the second one

    Infix notation can be used with operator '<<'

    @headerref{<boost/simd/function/shift_left.hpp>}

    @par Description

      @code
      Value shift_left(Value const& x, IntegerValue const& n);
      @endcode

    @par Note:
      - on many architectures a scalar second parameter results in a much faster call

    @see  shift_right, shr, rshl, rshr, rol, ror


   @par Example:

      @snippet shift_left.cpp shift_left

    @par Possible output:

      @snippet shift_left.txt shift_left

  **/

#include <boost/simd/function/scalar/shift_left.hpp>
#include <boost/simd/function/simd/shift_left.hpp>

#endif
