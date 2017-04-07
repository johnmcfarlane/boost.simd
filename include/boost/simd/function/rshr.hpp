//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RSHR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RSHR_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-rshr rshr (function object)

    This function object returns the first entry shifted right or left
    by the absolute value of the second entry,
    according to its sign.

    @headerref{<boost/simd/function/rshr.hpp>}

    @par Description

      @code
      Value rshr(Value const& x, IntegerValue const& n);
      @endcode

    @see ( %real ) [rshl](@ref real-rshl), [shr](@ref real-shr), [shl](@ref real-shl)

    @par Example:

      @snippet rshr.cpp rshr

    @par Possible output:

      @snippet rshr.txt rshr

  **/

#include <boost/simd/function/scalar/rshr.hpp>
#include <boost/simd/function/simd/rshr.hpp>

#endif
