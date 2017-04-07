//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ATAN2D_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ATAN2D_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-atan2d atan2d (function object)

    This function object returns the atan2d function : atan2 in degrees.

    @headerref{<boost/simd/function/atan2d.hpp>}

    @par Description

      @code
      IEEEValue atan2d(IEEEValue const& y, IEEEValue const& x );
      @endcode

    @par Note

      For every parameters of same floating type
      `atan2d(y, x)` is similar  to: `indeg(atan2(y, x))`

    @see ( %real ) [atan2](@ref real-atan2), [atan2pi](@ref real-atan2pi)

    @par Example:

      @snippet atan2d.cpp atan2d

    @par Possible output:

      @snippet atan2d.txt atan2d

  **/

#include <boost/simd/function/scalar/atan2d.hpp>
#include <boost/simd/function/simd/atan2d.hpp>

#endif
