//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_LESS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_LESS_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_less is_less (function object)

    This function object returns  @ref True or @ref False according x is less than y or not.
    Infix notation can be used with operator '<'.

    @headerref{<boost/simd/function/is_less.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_less(Value const& x, Value const& y);
      @endcode

    @par Note

     Using `is_less(x,y)` is equivalent to `x < y`

    @par Example:

      @snippet is_less.cpp is_less

    @par Possible output:

      @snippet is_less.txt is_less

  **/

#include <boost/simd/function/scalar/is_less.hpp>
#include <boost/simd/function/simd/is_less.hpp>

#endif
