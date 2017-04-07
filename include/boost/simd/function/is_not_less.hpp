//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_LESS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_LESS_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_not_less is_not_less (function object)

    This function object returns   [True](@ref constant-True) or  [False](@ref constant-False) according x is not less than y or not.

    @headerref{<boost/simd/function/is_not_less.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_not_less(Value const& x, Value const& y);
      @endcode

    @par Note

     Using `is_not_less(x,y)` is similar to: `!(x < y)`

    @par Example:

      @snippet is_not_less.cpp is_not_less

    @par Possible output:

      @snippet is_not_less.txt is_not_less

  **/

#include <boost/simd/function/scalar/is_not_less.hpp>
#include <boost/simd/function/simd/is_not_less.hpp>

#endif
