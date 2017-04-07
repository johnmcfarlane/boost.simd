//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_LEZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_LEZ_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_lez is_lez (function object)

    This function object returns  [True](@ref constant-True) or  [False](@ref constant-False) according x is less or equal to  [Zero](@ref constant-Zero) or not.

    @headerref{<boost/simd/function/is_lez.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_lez(Value const& x);
      @endcode

    @par Note

     Using `is_lez(x)` is similar to: `x <= 0`

    @par Example:

      @snippet is_lez.cpp is_lez

    @par Possible output:

      @snippet is_lez.txt is_lez

  **/

#include <boost/simd/function/scalar/is_lez.hpp>
#include <boost/simd/function/simd/is_lez.hpp>

#endif
