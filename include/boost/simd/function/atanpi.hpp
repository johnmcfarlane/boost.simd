//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ATANPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ATANPI_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-atanpi atanpi (function object)

    This function object returns the inverse tangent in \f$\pi\f$ multiples.

    @headerref{<boost/simd/function/atanpi.hpp>}

    @par Description

      @code
      IEEEValue atanpi(IEEEValue const& x);
      @endcode

    @par Note

      For every parameter of floating type `atanpi(x)`
      returns the arc @c r in the interval  \f$[-0.5, 0.5[\f$
      such that <tt>tanpi(r) == x</tt>.

    @see atan2, atan2d, atand, atan, tanpi


    @par Example:

      @snippet atanpi.cpp atanpi

    @par Possible output:

      @snippet atanpi.txt atanpi

  **/

#include <boost/simd/function/scalar/atanpi.hpp>
#include <boost/simd/function/simd/atanpi.hpp>

#endif
