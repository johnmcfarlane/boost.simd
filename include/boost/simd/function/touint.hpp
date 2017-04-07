//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TOUINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TOUINT_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-touint touint (function object)

    This function object converts its parameter to unsigned integer by truncation.

    @headerref{<boost/simd/function/touint.hpp>}

    @par Description

      @code
      as_integer_t<Value, unsigned> touint(Value const& x);
      @endcode

    @par Decorators

    - saturated_ (See @ref [group](@ref real-group)-decorator) as stated above ensures good behaviour on
      limiting values.

    @par Notes

    @see ( %real ) [toint](@ref real-toint), [tofloat](@ref real-tofloat)

    @par Example:

      @snippet touint.cpp touint

    @par Possible output:

      @snippet touint.txt touint


  **/

#include <boost/simd/function/scalar/touint.hpp>
#include <boost/simd/function/simd/touint.hpp>

#endif
