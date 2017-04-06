//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINMAG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINMAG_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-minmag minmag (function object)

    This function object returns the input value which have the least absolute value.

    @headerref{<boost/simd/function/minmag.hpp>}

    @par Description

      @code
      Value minmag(Value const& x, Value const& y);
      @endcode

    @par Example:

      @snippet minmag.cpp minmag

    @par Possible output:

      @snippet minmag.txt minmag

  **/

#include <boost/simd/function/scalar/minmag.hpp>
#include <boost/simd/function/simd/minmag.hpp>

#endif
