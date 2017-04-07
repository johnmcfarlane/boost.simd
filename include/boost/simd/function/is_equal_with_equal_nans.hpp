//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_EQUAL_WITH_EQUAL_NANS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_EQUAL_WITH_EQUAL_NANS_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_equal_with_equal_nans is_equal_with_equal_nans (function object)

    This unction object returns  [True](@ref constant-True) or  [False](@ref constant-False) according x and y are equal or not.
    Nans are considered equal

    @headerref{<boost/simd/function/is_equal_with_equal_nans.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_equal_with_equal_nans(Value const& x, Value const& y);
      @endcode

    @par Note

    Using `is_equal_with_equal_nans(x,y)` is similar to `(x == y) || ((x!= x) && (y!= y))`

    @see ( %real ) [Nan](@ref constant-Nan)

    @par Example:

      @snippet is_equal_with_equal_nans.cpp is_equal_with_equal_nans

    @par Possible output:

      @snippet is_equal_with_equal_nans.txt is_equal_with_equal_nans

  **/

#include <boost/simd/function/scalar/is_equal_with_equal_nans.hpp>
#include <boost/simd/function/simd/is_equal_with_equal_nans.hpp>

#endif
