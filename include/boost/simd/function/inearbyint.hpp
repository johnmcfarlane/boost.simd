//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INEARBYINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INEARBYINT_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-inearbyint inearbyint (function object)

    This function object computes the integer conversion of the  [nearbyint](@ref real-nearbyint) of its parameter.

    @headerref{<boost/simd/function/inearbyint.hpp>}

    @par Description

      @code
      as_integer_t<Value> inearbyint(Value const& x);
      @endcode

    @par Decorators:

   - pedantic_ if you need a full range correctness
     use this decorator that computes  saturated_(toint)(nearbyint(x));

    @par Note:
    This operation is NOT properly saturated.
    To ensure proper saturation use the decorartor pedantic_

    @see ( %real ) [nearbyint](@ref real-nearbyint), [ifloor](@ref real-ifloor), [iround](@ref real-iround), [ifix](@ref real-ifix), [iceil](@ref real-iceil)

    @par Example:

      @snippet inearbyint.cpp inearbyint

    @par Possible output:

      @snippet inearbyint.txt inearbyint

  **/

#include <boost/simd/function/scalar/inearbyint.hpp>
#include <boost/simd/function/simd/inearbyint.hpp>

#endif
