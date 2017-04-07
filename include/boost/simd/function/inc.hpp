//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INC_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-inc inc (function object)

    This function object returns  its parameter incremented by 1.

    @headerref{<boost/simd/function/inc.hpp>}

    @par Description

      @code
      Value inc(Value const& x);
      @endcode

    @par Decorators

     - saturated_ ensures that @c saturated_(inc)(x) will never be strictly
     less than @c x, avoiding the wrap around from @ref Valmax to
    @see ( %real ) [plus](@ref real-plus), [dec](@ref real-dec), [minus](@ref real-minus)

    @par Example:

      @snippet inc.cpp inc

    @par Possible output:

      @snippet inc.txt inc
  **/

#include <boost/simd/function/scalar/inc.hpp>
#include <boost/simd/function/simd/inc.hpp>

#endif
