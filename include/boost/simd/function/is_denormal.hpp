//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_DENORMAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_DENORMAL_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_denormal is_denormal (function object)

    This function object returns  [True](@ref constant-True) or  [False](@ref constant-False) according x is denormal or not.

    @headerref{<boost/simd/function/is_denormal.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_denormal(Value const& x);
      @endcode

    @par Note

    Using `is_denormal(x)` is similar to `(x != 0) && (abs(x) < Smallestposval<T>())`

    @see ( %real ) [Smallestposval](@ref constant-Smallestposval)

    @par Example:

      @snippet is_denormal.cpp is_denormal

    @par Possible output:

      @snippet is_denormal.txt is_denormal


  **/

#include <boost/simd/function/scalar/is_denormal.hpp>
#include <boost/simd/function/simd/is_denormal.hpp>

#endif
