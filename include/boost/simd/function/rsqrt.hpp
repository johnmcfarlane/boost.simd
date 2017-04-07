//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RSQRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RSQRT_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-rsqrt rsqrt (function object)

    This function object returns the inverse of the square root of the input.

    @headerref{<boost/simd/function/rsqrt.hpp>}

    @par Description

      @code
      IEEEValue rsqrt(IEEEValue const& x);
      @endcode

    @par Decorators

    - raw_  if full accuracy is not needed gives access on some architectures to faster
    but less accurate version of the function.

    @see ( %real ) [sqrt](@ref real-sqrt)

    @par Example:

      @snippet rsqrt.cpp rsqrt

    @par Possible output:

      @snippet rsqrt.txt rsqrt


  **/

#include <boost/simd/function/scalar/rsqrt.hpp>
#include <boost/simd/function/scalar/rsqrt.hpp>
#include <boost/simd/function/simd/rsqrt.hpp>

#endif
