//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_RSHL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RSHL_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-rshl rshl (function object)

    This function object returns the first entry shifted left or right
    by the absolute value of the second entry,
    according to its sign.

    @headerref{<boost/simd/function/rshl.hpp>}

    @par Description

      @code
      Value rshl(Value const& x, IntegerValue const& n);
      @endcode

    @see ( %real ) [rshr](@ref real-rshr), [shr](@ref real-shr), [shl](@ref real-shl)

    @par Example:

      @snippet rshl.cpp rshl

    @par Possible output:

      @snippet rshl.txt rshl

  **/

#include <boost/simd/function/scalar/rshl.hpp>
#include <boost/simd/function/simd/rshl.hpp>

#endif
