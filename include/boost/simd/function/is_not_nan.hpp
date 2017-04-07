//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_NAN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_NAN_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_not_nan is_not_nan (function object)

    This function object returns  [False](@ref constant-False) or  [True](@ref constant-True) according x is  [Nan](@ref constant-Nan) or not.

    @headerref{<boost/simd/function/is_not_nan.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_not_nan(Value const& x);
      @endcode

    @par Note

     Using `is_not_nan(x)` is similar to: `x == x`

    @par Example:

      @snippet is_not_nan.cpp is_not_nan

    @par Possible output:

      @snippet is_not_nan.txt is_not_nan

  **/

#include <boost/simd/function/scalar/is_not_nan.hpp>
#include <boost/simd/function/simd/is_not_nan.hpp>

#endif
