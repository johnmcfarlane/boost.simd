//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NGTZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NGTZ_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_ngtz is_ngtz (function object)

    This function object returns @ref True if x is not greater than @ref Zero else returns @ref False.

    @headerref{<boost/simd/function/is_ngtz.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_ngtz(Value const& x);
      @endcode

    @par Note

     Using `is_ngtz(x)` is similar to: `!(x > 0)`

    @par Example:

      @snippet is_ngtz.cpp is_ngtz

    @par Possible output:

      @snippet is_ngtz.txt is_ngtz

  **/

#include <boost/simd/function/scalar/is_ngtz.hpp>
#include <boost/simd/function/simd/is_ngtz.hpp>

#endif
