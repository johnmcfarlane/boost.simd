//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_LESSGREATER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_LESSGREATER_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_lessgreater is_lessgreater (function object)

    This function object returns @ref [True](@ref constant-True) if neither x nor y is @ref [Nan](@ref constant-Nan) and x is not equal to y.

    @headerref{<boost/simd/function/is_lessgreater.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_lessgreater(Value const& x, Value const& y);
      @endcode

    @par Decorators

     - std_ can be used to call std::islessgreater

    @par Note

     Using `is_lessgreater(x,y)` is similar to: `(x == x) && (y == y) && (x!= y)`

    @par Example:

      @snippet is_lessgreater.cpp is_lessgreater

    @par Possible output:

      @snippet is_lessgreater.txt is_lessgreater

  **/

#include <boost/simd/function/scalar/is_lessgreater.hpp>
#include <boost/simd/function/simd/is_lessgreater.hpp>

#endif
