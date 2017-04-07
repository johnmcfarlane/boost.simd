//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CEIL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CEIL_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-ceil ceil (function object)

    This function object computes the smallest integral representable value of
    its parameter type which is greater or equal to it.

    @headerref{<boost/simd/function/ceil.hpp>}

    @par Description

      @code
      Value ceil(Value const& x);
      @endcode

    @par Decorators

    - std_ for floating entries call std::ceil

    @par Notes

     - @c ceil is also used as parameter to pass to  [div](@ref real-div) or  [rem](@ref real-rem)

    @see ( %real ) [floor](@ref real-floor), [round](@ref real-round), [nearbyint](@ref real-nearbyint), [trunc](@ref real-trunc), [iceil](@ref real-iceil)

    @par Example:

      @snippet ceil.cpp ceil

    @par Possible output:

      @snippet ceil.txt ceil

  **/

#include <boost/simd/function/scalar/ceil.hpp>
#include <boost/simd/function/simd/ceil.hpp>

#endif
