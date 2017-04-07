//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIVIDES_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIVIDES_HPP_INCLUDED

  /*!
    @ingroup group-operator
    @defgroup real-divides divides (function object)

    Function object implementing divides capabilities

    Perform the quotient of two parameters of the same type.
    Infix notation can be used with operator '/'.

    @headerref{<boost/simd/function/divides.hpp>}

    @par Description

      @code
      Value divides(Value const& x, Value const& y);
      @endcode

    @par Decorators

     - `saturated_` (See @ref [group](@ref real-group)-decorator) computes the saturated division. The only
     difference is to allow for integer types to divide @ref [Valmin](@ref constant-Valmin) by -1 returning @ref [Valmax](@ref constant-Valmax).
     In the regular case (no decorator) the result is undefined.

    @par Note

    As usual the simd division is often more expansive than the other
    arithmetic operators and using the @ref [rec](@ref real-rec) function or @ref [shift_right](@ref real-shift_right) function
    can be sometimes handy to gain some cycles.

    @see ( %real ) [div](@ref real-div), [rem](@ref real-rem), [rec](@ref real-rec), [shift_right](@ref real-shift_right)

    @par Example:

      @snippet divides.cpp divides

    @par Possible output:

      @snippet divides.txt divides

  **/

#include <boost/simd/function/scalar/divides.hpp>
#include <boost/simd/function/scalar/divides.hpp>
#include <boost/simd/function/simd/divides.hpp>

#endif
