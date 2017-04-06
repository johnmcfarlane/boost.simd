//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SQRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SQRT_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-sqrt sqrt (function object)

    This function object computes the square root of its parameter.
    For integers it is the truncation of the real square root.

    @headerref{<boost/simd/function/sqrt.hpp>}

    @par Description

      @code
      Value sqrt(Value const& x);
      @endcode

    @par Decorators

    - std_ calls std::sqrt

    - raw_ for floating entries can gain some speed with less accuracy
    on some architectures.

    @see rsqrt, sqr_abs, sqr

    @par Example:

      @snippet sqrt.cpp sqrt

    @par Possible output:

      @snippet sqrt.txt sqrt

  **/

#include <boost/simd/function/scalar/sqrt.hpp>
#include <boost/simd/function/simd/sqrt.hpp>

#endif
