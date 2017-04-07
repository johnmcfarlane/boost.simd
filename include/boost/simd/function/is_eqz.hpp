//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_EQZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_EQZ_HPP_INCLUDED

  /*!
    @ingroup group-predicates
    @defgroup real-is_eqz is_eqz (function object)

    This function object returns @ref [True](@ref constant-True) or @ref [False](@ref constant-False) according x is @ref [Zero](@ref constant-Zero) or not.

    @headerref{<boost/simd/function/is_eqz.hpp>}

    @par Description

      @code
      as_logical_t<Value> is_eqz(Value const& x);
      @endcode

    @par Note

      Using `is_eqz(x)` is equivalent to `x == 0`

    @see ( %real ) [is_nez](@ref real-is_nez), [is_lez](@ref real-is_lez), [is_ltz](@ref real-is_ltz)

    @par Example:

      @snippet is_eqz.cpp is_eqz

    @par Possible output:

      @snippet is_eqz.txt is_eqz

  **/

#include <boost/simd/function/scalar/is_eqz.hpp>
#include <boost/simd/function/simd/is_eqz.hpp>

#endif
