//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_FLINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_FLINT_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_flint is_flint (function object)

    This function object returns @ref [True](@ref constant-True) or @ref [False](@ref constant-False) according x is a flint or not.

    @headerref{<boost/simd/function/is_flint.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_flint(Value const& x);
      @endcode

    @par Note

    A flint is a 'floating integer' i.e. a floating number
    representing exactly an integer value.

    Be conscious that all sufficiently great floating points values
    are flint and even are even...

    @par Example:

      @snippet is_flint.cpp is_flint

    @par Possible output:

      @snippet is_flint.txt is_flint

  **/

#include <boost/simd/function/scalar/is_flint.hpp>
#include <boost/simd/function/simd/is_flint.hpp>

#endif
