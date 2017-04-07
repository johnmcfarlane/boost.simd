//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ATAN2PI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ATAN2PI_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-atan2pi atan2pi (function object)

    This function object returns the atan2pi function : atan2 in pi multiples.

    @headerref{<boost/simd/function/atan2pi.hpp>}

    @par Description

      @code
      IEEEValue atan2pi(IEEEValue const& y, const IEEEValue& x);
      @endcode

    @par Note

      For every parameters of same floating type `atan2pi(y, x)`
      is similar  to: `atan2(y, x)/Pi`


    @see ( %real ) [atan2](@ref real-atan2), [atan2pi](@ref real-atan2pi)

    @par Example:

      @snippet atan2pi.cpp atan2pi

    @par Possible output:

      @snippet atan2pi.txt atan2pi

  **/

#include <boost/simd/function/scalar/atan2pi.hpp>
#include <boost/simd/function/simd/atan2pi.hpp>

#endif
