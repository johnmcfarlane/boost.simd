//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FIX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FIX_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-fix fix (function object)

    This function object computes the truncation toward  [Zero](@ref constant-Zero)
    of its parameter.

    @headerref{<boost/simd/function/fix.hpp>}

    @par Description

      @code
      Value fix(Value const& x);
      @endcode

    @see ( %real ) [ceil](@ref real-ceil), [floor](@ref real-floor), [round](@ref real-round), [nearbyint](@ref real-nearbyint), [trunc](@ref real-trunc), [ifix](@ref real-ifix), [itrunc](@ref real-itrunc)

    @par Example:

      @snippet fix.cpp fix

    @par Possible output:

      @snippet fix.txt fix

  **/

#include <boost/simd/function/scalar/trunc.hpp>
#include <boost/simd/function/simd/fix.hpp>

#endif
