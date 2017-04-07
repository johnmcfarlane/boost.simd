//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NOT_IMAG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NOT_IMAG_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_not_imag is_not_imag (function object)

    This function object returns @ref [True](@ref constant-True) or @ref [False](@ref constant-False) according x is not pure imaginary or is.

    For non complex numbers it is @ref [True](@ref constant-True) except if x is @ref [Zero](@ref constant-Zero).

    @headerref{<boost/simd/function/is_not_imag.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_not_imag(Value const& x);
      @endcode

    @par Note

     Using `is_not_imag(x)` is similar to: `x != 0` for real entries.

    @par Example:

      @snippet is_not_imag.cpp is_not_imag

    @par Possible output:

      @snippet is_not_imag.txt is_not_imag

  **/

#include <boost/simd/function/scalar/is_not_imag.hpp>
#include <boost/simd/function/scalar/is_not_imag.hpp>
#include <boost/simd/function/simd/is_not_imag.hpp>

#endif
