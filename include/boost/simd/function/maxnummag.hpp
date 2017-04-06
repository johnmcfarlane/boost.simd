//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MAXNUMMAG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MAXNUMMAG_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-maxnummag maxnummag (function object)

    This function object returns between two floating point arguments,
    the one  having the greatest absolute value, treating NaNs
    as missing data (between a NaN and a numeric value, the numeric value is chosen).

    @headerref{<boost/simd/function/maxnummag.hpp>}

    @par Description

      @code
      Value maxnummag(Value const& x, Value const& y);
      @endcode

    @par Example:

      @snippet maxnummag.cpp maxnummag

    @par Possible output:

      @snippet maxnummag.txt maxnummag

  **/

#include <boost/simd/function/scalar/maxnummag.hpp>
#include <boost/simd/function/simd/maxnummag.hpp>

#endif
