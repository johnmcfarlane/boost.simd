//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ILOG2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ILOG2_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-ilog2 ilog2 (function object)

    This function object returns the integer part of the base 2
    logarithm of the input.

    @headerref{<boost/simd/function/ilog2.hpp>}

    @par Description

      @code
      as_integer_t<Value> ilog2(Value const& x);
      @endcode

    @par Note
    This function asserts for negative or null values.

    @see ( %real ) [twopower](@ref real-twopower), [exponent](@ref real-exponent)

    @par Example:

      @snippet ilog2.cpp ilog2

    @par Possible output:

      @snippet ilog2.txt ilog2

  **/

#include <boost/simd/function/scalar/ilog2.hpp>
#include <boost/simd/function/simd/ilog2.hpp>

#endif
