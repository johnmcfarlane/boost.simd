//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFLOOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFLOOR_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-ifloor ifloor (function object)

    This function object computes the integer conversion of the @ref floor of its parameter.

    @headerref{<boost/simd/function/ifloor.hpp>}

    @par Description

      @code
      as_integer_t<Value> ifloor(Value const& x);
      @endcode

    @par Note:
    This operation is properly saturated

    @see ( %real ) [floor](@ref real-floor), [ifloor](@ref real-ifloor), [iround](@ref real-iround), [ifix](@ref real-ifix), [inearbyint](@ref real-inearbyint)

    @par Example:

      @snippet ifloor.cpp ifloor

    @par Possible output:

      @snippet ifloor.txt ifloor

  **/

#include <boost/simd/function/scalar/ifloor.hpp>
#include <boost/simd/function/simd/ifloor.hpp>

#endif
