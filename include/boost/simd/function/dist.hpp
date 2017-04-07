//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIST_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIST_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-dist dist (function object)

    This function object computes the absolute value of the difference of its parameters.

    @headerref{<boost/simd/function/dist.hpp>}

    @par Description

      @code
      Value dist(Value const& x, Value const& y);
      @endcode

    @par Decorators

     - saturated_ garanties that @c saturated_(dist)(x, y)) will
       never be strictly less than 0.

    @par Notes

    The result may be negative for signed integers as  [abs](@ref real-abs)( [Valmin](@ref constant-Valmin)) is undefined.
    To avoid the problem you can apply to dist the saturated_ decorator (See  [group](@ref real-group)-decorator.)

    @see ( %real ) [ulpdist](@ref real-ulpdist), [abs](@ref real-abs)

    @par Example:

      @snippet dist.cpp dist

    @par Possible output:

      @snippet dist.txt dist

  **/

#include <boost/simd/function/scalar/dist.hpp>
#include <boost/simd/function/simd/dist.hpp>

#endif
