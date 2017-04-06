//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NAN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NAN_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_nan is_nan (function object)

    This function object returns @ref True or @ref False according x is nan or not.

    @headerref{<boost/simd/function/is_nan.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_nan(Value const& x);
      @endcode

    @par Note

     Using `is_nan(x)` is similar to `x != x`

    @par Example:

      @snippet is_nan.cpp is_nan

    @par Possible output:

      @snippet is_nan.txt is_nan

  **/

#include <boost/simd/function/scalar/is_nan.hpp>
#include <boost/simd/function/simd/is_nan.hpp>

#endif
