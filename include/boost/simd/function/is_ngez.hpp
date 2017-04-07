//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NGEZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NGEZ_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_ngez is_ngez (function object)

    This function object returns @ref [True](@ref constant-True) if x is not greater or equal to @ref [Zero](@ref constant-Zero) else returns @ref [False](@ref constant-False).

    @headerref{<boost/simd/function/is_ngez.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_ngez(Value const& x);
      @endcode

    @par Note

     Using `is_ngez(x)` is similar to: `!(x >= 0)`

    @par Example:

      @snippet is_ngez.cpp is_ngez

    @par Possible output:

      @snippet is_ngez.txt is_ngez

  **/

#include <boost/simd/function/scalar/is_ngez.hpp>
#include <boost/simd/function/simd/is_ngez.hpp>

#endif
