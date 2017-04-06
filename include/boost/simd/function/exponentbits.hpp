//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXPONENTBITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXPONENTBITS_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-exponentbits exponentbits (function object)

    This function object returns the exponent bits of its arguments as an integer value,
    the other bits (sign and mantissa) being just masked.

    @headerref{<boost/simd/function/exponentbits.hpp>}

    @par Description

      @code
      as_integer_t<IEEEValue> exponentbits(IEEEValue const& x);
      @endcode

    @par Example:

      @snippet exponentbits.cpp exponentbits

    @par Possible output:

      @snippet exponentbits.txt exponentbits

  **/

#include <boost/simd/function/scalar/exponentbits.hpp>
#include <boost/simd/function/simd/exponentbits.hpp>

#endif
