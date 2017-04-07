//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_DENORMAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_DENORMAL_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_not_denormal is_not_denormal (function object)

    This function object returns  [True](@ref constant-True) or  [False](@ref constant-False) according x is not denormal.

    @headerref{<boost/simd/function/is_not_denormal.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_not_denormal(Value const& x);
      @endcode

    @par Note

     Using `is_not_denormal(x)` is similar to `!(abs(x) < Smallestposval<T>()) || (x == 0)`

    @par Example:

      @snippet is_not_denormal.cpp is_not_denormal

    @par Possible output:

      @snippet is_not_denormal.txt is_not_denormal

  **/

#include <boost/simd/function/scalar/is_not_denormal.hpp>
#include <boost/simd/function/simd/is_not_denormal.hpp>

#endif
