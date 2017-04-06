//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHL_HPP_INCLUDED

  /*!
    @ingroup group-operator
    @defgroup real-shl shl (function object)

     This function object returns the first operand shifted left by the second one

    Infix notation can be used with operator '<<'

    @headerref{<boost/simd/function/shl.hpp>}

    @par Description

      @code
      Value shl(Value const& x, IntegerValue const& n);
      @endcode

  **/

#include <boost/simd/function/scalar/shift_left.hpp>
#include <boost/simd/function/simd/shl.hpp>

#endif
