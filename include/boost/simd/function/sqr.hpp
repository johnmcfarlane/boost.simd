//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SQR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SQR_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-sqr sqr (function object)

    This function computes the square of its parameter.

    @headerref{<boost/simd/function/sqr.hpp>}

    @par Description

      @code
      Value sqr(Value const& x);
      @endcode

    @par Decorators

    - saturated_ for integer entries ensure that sqr(x) is never strictly less than x

    @see ( %real ) [sqrt](@ref real-sqrt), [sqr_abs](@ref real-sqr_abs)

    @par Example:

      @snippet sqr.cpp sqr

    @par Possible output:

      @snippet sqr.txt sqr


  **/

#include <boost/simd/function/scalar/sqr.hpp>
#include <boost/simd/function/simd/sqr.hpp>

#endif
