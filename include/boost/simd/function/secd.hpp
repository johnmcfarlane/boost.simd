//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SECD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SECD_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-secd secd (function object)

    This function object returns the secant of the angle in degree:
    \f$1/\cos(\pi x/180)\f$.

    @headerref{<boost/simd/function/secd.hpp>}

    @par Description

      @code
      IEEEValue secd(IEEEValue const& x);
      @endcode

    @see cosd, sec, secpi



    @par Example:

      @snippet secd.cpp secd

    @par Possible output:

      @snippet secd.txt secd

  **/

#include <boost/simd/function/scalar/secd.hpp>
#include <boost/simd/function/simd/secd.hpp>

#endif
