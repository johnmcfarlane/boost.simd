//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACOTD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACOTD_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-acotd acotd (function object)

    This function object returns the inverse cotangent in degree.

    @headerref{<boost/simd/function/acotd.hpp>}

    @par Description

      @code
      IEEEValue acotd(IEEEValue const & x);
      @endcode

    @par Note

      For every parameter of floating type `acotd(x)`
      returns the arc @c r in the interval  \f$[0, 180[\f$ such that
      <tt>cotd(r) == x</tt>.

    @see ( %real ) [acot](@ref real-acot), [acotpi](@ref real-acotpi), [cotd](@ref real-cotd)

    @par Example:

      @snippet acotd.cpp acotd

    @par Possible output:

      @snippet acotd.txt acotd

  **/

#include <boost/simd/function/scalar/acotd.hpp>
#include <boost/simd/function/simd/acotd.hpp>

#endif
