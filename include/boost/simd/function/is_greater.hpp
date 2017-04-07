//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_GREATER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_GREATER_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_greater is_greater (function object)

    This function object returns  [True](@ref constant-True) or  [False](@ref constant-False) according
    x is greater than y or not.

    Infix notation can be used with operator '>'.

    @headerref{<boost/simd/function/is_greater.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_greater(Value const& x, Value const& y);
      @endcode

    @par Note

    Using `is_greater(x,y)` is equivalent to `x > y`

    @see ( %real ) [is_greater_equal](@ref real-is_greater_equal), [is_gtz](@ref real-is_gtz), [is_not_less_equal](@ref real-is_not_less_equal), [is_not_less](@ref real-is_not_less)

    @par Example:

      @snippet is_greater.cpp is_greater

    @par Possible output:

      @snippet is_greater.txt is_greater

  **/

#include <boost/simd/function/scalar/is_greater.hpp>
#include <boost/simd/function/simd/is_greater.hpp>

#endif
