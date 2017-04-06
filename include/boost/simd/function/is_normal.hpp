//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NORMAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NORMAL_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_normal is_normal (function object)

    This function object returns @ref True or @ref False according x is normal or not.

    @headerref{<boost/simd/function/is_normal.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_normal(Value const& x);
      @endcode

    @par Note

     Using  `is_normal(x)` is similar to `!(is_denormal(x) || is_invalid(x) || !(x == 0)`

    @par Example:

      @snippet is_normal.cpp is_normal

    @par Possible output:

      @snippet is_normal.txt is_normal

  **/

#include <boost/simd/function/scalar/is_normal.hpp>
#include <boost/simd/function/scalar/is_normal.hpp>
#include <boost/simd/function/simd/is_normal.hpp>

#endif
