//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NLTZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NLTZ_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_nltz is_nltz (function object)

    This function object returns  [True](@ref constant-True) if x is not less than  [Zero](@ref constant-Zero) else returns  [False](@ref constant-False).

    @headerref{<boost/simd/function/is_nltz.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_nltz(Value const& x);
      @endcode

    @par Note

     Using `is_nltz(x)` is similar to: `!(x < 0)`

    @par Example:

      @snippet is_nltz.cpp is_nltz

    @par Possible output:

      @snippet is_nltz.txt is_nltz

  **/

#include <boost/simd/function/scalar/is_nltz.hpp>
#include <boost/simd/function/simd/is_nltz.hpp>

#endif
