//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_SIMD_LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_SIMD_LOGICAL_HPP_INCLUDED

  /*!
    @ingroup group-reduction
    @defgroup real-is_simd_logical is_simd_logical (function object)

    returns  [True](@ref constant-True) if each vector elements have all bits or no bit set.

    @headerref{<boost/simd/function/is_simd_logical.hpp>}

    @par Description

      @code
      bool is_simd_logical(Value const& x);
      @endcode

    @par Note

     Using `is_simd_logical(x)` is similar to `all(logical_or(x == Allbits(as(x)), x == Zero(as(x))))`

  **/

#include <boost/simd/function/scalar/is_simd_logical.hpp>
#include <boost/simd/function/simd/is_simd_logical.hpp>

#endif
