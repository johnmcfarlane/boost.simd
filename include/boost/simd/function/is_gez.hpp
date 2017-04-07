//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_GEZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_GEZ_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_gez is_gez (function object)

    This function object returns @ref [True](@ref constant-True) or @ref [False](@ref constant-False) according x
    is greater or equal to @ref [Zero](@ref constant-Zero) or not.

    @headerref{<boost/simd/function/is_gez.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_gez(Value const& x);
      @endcode

    @par Note

      Using `is_gez(x)` is equivalent to `x >= 0`

    @par Example:

      @snippet is_gez.cpp is_gez

    @par Possible output:

      @snippet is_gez.txt is_gez

  **/

#include <boost/simd/function/scalar/is_gez.hpp>
#include <boost/simd/function/simd/is_gez.hpp>

#endif
