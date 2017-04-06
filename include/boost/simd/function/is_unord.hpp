//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_UNORD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_UNORD_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_unord is_unord (function object)

    This function object returns @ref True if x or y is nan.

    @headerref{<boost/simd/function/is_unord.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_unord(Value const& x, Value const& y);
      @endcode

    @par Note

     Using `is_unord(x,y)` is similar to: `(x != x) || (y != y)`

    @par Example:

      @snippet is_unord.cpp is_unord

    @par Possible output:

      @snippet is_unord.txt is_unord

  **/

#include <boost/simd/function/scalar/is_unord.hpp>
#include <boost/simd/function/simd/is_unord.hpp>

#endif
