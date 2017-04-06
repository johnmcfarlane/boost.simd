//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACOT_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-acot acot (function object)

    This function object returns the inverse cotangent.

    @headerref{<boost/simd/function/acot.hpp>}

    @par Description

      @code
      IEEEValue acot(IEEEValue const & x);
      @endcode

    @par Note

      For every parameter of floating type `r = acot(x)`
      returns the arc @c r in the interval  \f$[0, \pi[\f$ such that
      <tt>cot(r) == x</tt>.

    @see acotd, acotpi, cot


    @par Example:

      @snippet acot.cpp acot

    @par Possible output:

      @snippet acot.txt acot

  **/

#include <boost/simd/function/scalar/acot.hpp>
#include <boost/simd/function/simd/acot.hpp>

#endif
