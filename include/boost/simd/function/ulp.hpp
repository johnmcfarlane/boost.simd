//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ULP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ULP_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-ulp ulp (function object)

    This function object returns the ulp distance to the nearest (distinct) element of the same type.

    @headerref{<boost/simd/function/ulp.hpp>}

    @par Description

      @code
      Value ulp(Value const& x);
      @endcode

    @see ( %real ) [ulpdist](@ref real-ulpdist), [eps](@ref real-eps), [Eps](@ref constant-Eps)

    @par Example:

      @snippet ulp.cpp ulp

    @par Possible output:

      @snippet ulp.txt ulp

  **/

#include <boost/simd/function/scalar/ulp.hpp>
#include <boost/simd/function/simd/ulp.hpp>

#endif
