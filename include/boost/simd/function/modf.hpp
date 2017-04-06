//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MODF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MODF_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-modf modf (function object)

    This function object returns the integral and fractional parts of the input.

    @headerref{<boost/simd/function/modf.hpp>}

    @par Description

      @code

      @endcode

    @par Decorators

     - std_ calls std::modf to compute the pair of outputs.

    @par Example:

      @snippet modf.cpp modf

    @par Possible output:

      @snippet modf.txt modf

  **/

#include <boost/simd/function/scalar/modf.hpp>
#include <boost/simd/function/simd/modf.hpp>

#endif
