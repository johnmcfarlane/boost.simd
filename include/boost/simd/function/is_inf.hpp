//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_INF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_INF_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_inf is_inf (function object)

    This function object returns  [True](@ref constant-True) if x is inf or -inf else returns  [False](@ref constant-False).

    @headerref{<boost/simd/function/is_inf.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_inf(Value const& x);
      @endcode

    @par Note

     Using `is_inf(x)` is similar to `(x == Inf) || (x == -Inf)`

    @par Example:

      @snippet is_inf.cpp is_inf

    @par Possible output:

      @snippet is_inf.txt is_inf

  **/

#include <boost/simd/function/scalar/is_inf.hpp>
#include <boost/simd/function/simd/is_inf.hpp>

#endif
