//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IROUND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IROUND_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-iround iround (function object)

    This function object computes the integer conversion of the  [round](@ref real-round) of its parameter.

    @headerref{<boost/simd/function/iround.hpp>}

    @par Description

      @code
      as_integer_t<Value> iround(Value const& x);
      @endcode

    @par Note:
    This operation is properly saturated

    @see ( %real ) [round](@ref real-round), [iround](@ref real-iround), [iround](@ref real-iround), [ifix](@ref real-ifix), [inearbyint](@ref real-inearbyint)

    @par Example:

      @snippet iround.cpp iround

    @par Possible output:

      @snippet iround.txt iround

  **/

#include <boost/simd/function/scalar/iround.hpp>
#include <boost/simd/function/simd/iround.hpp>

#endif
