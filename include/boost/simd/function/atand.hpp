//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ATAND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ATAND_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-atand atand (function object)

    This function object returns the inverse tangent in degree.

    @headerref{<boost/simd/function/atand.hpp>}

    @par Description

      @code
      IEEEValue atand(IEEEValue const& x);
      @endcode

    @par Note

      For every parameter of floating type `atand(x)`
      returns the arc @c r in the interval  \f$[-90, 90[\f$
      such that <tt>tand(r) == x</tt>.

    @see atan2d, atan2, atan, atanpi, tand


    @par Example:

      @snippet atand.cpp atand

    @par Possible output:

      @snippet atand.txt atand

  **/

#include <boost/simd/function/scalar/atand.hpp>
#include <boost/simd/function/simd/atand.hpp>

#endif
