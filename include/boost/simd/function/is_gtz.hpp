//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_GTZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_GTZ_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_gtz is_gtz (function object)

   This function object returns @ref [True](@ref constant-True) or @ref [False](@ref constant-False) according x is greater than @ref [Zero](@ref constant-Zero) or not.

    @headerref{<boost/simd/function/is_gtz.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_gtz(Value const& x);
      @endcode

    @par Note

     Using `is_gtz(x)` is similar to: `x > 0`

    @par Example:

      @snippet is_gtz.cpp is_gtz

    @par Possible output:

      @snippet is_gtz.txt is_gtz

  **/

#include <boost/simd/function/scalar/is_gtz.hpp>
#include <boost/simd/function/simd/is_gtz.hpp>

#endif
