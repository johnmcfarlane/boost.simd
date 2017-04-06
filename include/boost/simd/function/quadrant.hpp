//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_QUADRANT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_QUADRANT_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-quadrant quadrant (function object)

    This function object computes the quadrant of its parameter.

    @headerref{<boost/simd/function/quadrant.hpp>}

    @par Description

      @code
      Value quadrant(Value const& n);
      @endcode

    @par Example:

      @snippet quadrant.cpp quadrant

    @par Possible output:

      @snippet quadrant.txt quadrant

  **/

#include <boost/simd/function/scalar/quadrant.hpp>
#include <boost/simd/function/simd/quadrant.hpp>

#endif
