//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NEZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NEZ_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_nez is_nez (function object)

    This function object returns @ref [True](@ref constant-True) if x is not equal to @ref [Zero](@ref constant-Zero) else returns @ref [False](@ref constant-False).

    @headerref{<boost/simd/function/is_nez.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_nez(Value const& x);
      @endcode

    @par Note

     Using `is_nez(x)` is similar to: `x != 0`

    @par Example:

      @snippet is_nez.cpp is_nez

    @par Possible output:

      @snippet is_nez.txt is_nez

  **/

#include <boost/simd/function/scalar/is_nez.hpp>
#include <boost/simd/function/simd/is_nez.hpp>

#endif
