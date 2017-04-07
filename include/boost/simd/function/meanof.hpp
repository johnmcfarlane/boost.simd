//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MEANOF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MEANOF_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-meanof meanof (function object)

   This function object computes the arithmetic mean of its parameters.

    @headerref{<boost/simd/abs.hpp>}

    @par Description

      @code
      Value meanof(Value const& x, Value const& y);
      @endcode

    @par Note:
      This function does not overflow.

    @see ( %real ) [average](@ref real-average)

    @par Example:

      @snippet average.cpp average

    @par Possible output:

      @snippet average.txt average

  **/

#include <boost/simd/function/scalar/meanof.hpp>
#include <boost/simd/function/simd/meanof.hpp>

#endif
