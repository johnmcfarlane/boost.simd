//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_EQUAL_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_not_equal is_not_equal (function object)

    This function object returns @ref [True](@ref constant-True) if x and y are not equal else @ref [False](@ref constant-False).
    Infix notation can be used with operator '!='.

    @headerref{<boost/simd/function/is_not_equal.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_not_equal(Value const& x);
      @endcode

    @par Note

     Using `is_not_equal(x,y)` is equivalent to `x != y`

    @par Example:

      @snippet is_not_equal.cpp is_not_equal

    @par Possible output:

      @snippet is_not_equal.txt is_not_equal

  **/

#include <boost/simd/function/scalar/is_not_equal.hpp>
#include <boost/simd/function/simd/is_not_equal.hpp>

#endif
