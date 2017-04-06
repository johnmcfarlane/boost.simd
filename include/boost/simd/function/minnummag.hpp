//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINNUMMAG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINNUMMAG_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-minnummag minnummag (function object)

    This function object returns between two floating point arguments,
    the one  having the  smallest absolute value, treating NaNs
    as missing data (between a NaN and a numeric value, the numeric value is chosen).

    @headerref{<boost/simd/function/minnummag.hpp>}

    @par Description

      @code
      Value minnummag(Value const& x, Value const& y);
      @endcode

    @par Example:

      @snippet minnummag.cpp minnummag

    @par Possible output:

      @snippet minnummag.txt minnummag

  **/

#include <boost/simd/function/scalar/minnummag.hpp>
#include <boost/simd/function/simd/minnummag.hpp>

#endif
