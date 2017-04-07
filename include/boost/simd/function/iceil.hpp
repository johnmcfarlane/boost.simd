//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ICEIL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ICEIL_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-iceil iceil (function object)

    This function object computes the integer conversion of the  [ceil](@ref real-ceil) of its parameter.

    @headerref{<boost/simd/function/iceil.hpp>}

    @par Description

      @code
      as_integer_t<Value> iceil(Value const& x);
      @endcode

    @par Note:
    This operation is properly saturated

    @see ( %real ) [ceil](@ref real-ceil), [ifloor](@ref real-ifloor), [iround](@ref real-iround), [ifix](@ref real-ifix), [inearbyint](@ref real-inearbyint)

    @par Example:

      @snippet iceil.cpp iceil

    @par Possible output:

      @snippet iceil.txt iceil


  **/

#include <boost/simd/function/scalar/iceil.hpp>
#include <boost/simd/function/simd/iceil.hpp>

#endif
