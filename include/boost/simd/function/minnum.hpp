//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINNUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINNUM_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-minnum minnum (function object)

   This function object returns  the smaller of two floating point arguments, treating NaNs
    as missing data (between a NaN and a numeric value, the numeric value is chosen).

    @headerref{<boost/simd/function/minnum.hpp>}

    @par Description

      @code
      Value minnum(Value const& x, Value const& y);
      @endcode

    @par Decorators

      - std_ for floating entries calls the stdlibc++ function std::fmin.

    @see min, minmag, minnummag

    @par Example:

      @snippet minnum.cpp minnum

    @par Possible output:

      @snippet minnum.txt minnum


  **/

#include <boost/simd/function/scalar/minnum.hpp>
#include <boost/simd/function/simd/minnum.hpp>

#endif
