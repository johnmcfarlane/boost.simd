//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TOINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TOINT_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-toint toint (function object)

    This function object converts its parameter to integer by truncation.

    @headerref{<boost/simd/function/toint.hpp>}

    @par Description

      @code
      as_integer_t<Value> toint(Value const& x);
      @endcode

    @par Decorators

    - saturated_ (See @ref group-decorator) as stated above ensures good behaviour on
      limiting values.

    @par Notes

    @see ( %real ) [touint](@ref real-touint), [tofloat](@ref real-tofloat)

    @par Example:

      @snippet toint.cpp toint

    @par Possible output:

      @snippet toint.txt toint
  **/

#include <boost/simd/function/scalar/toint.hpp>
#include <boost/simd/function/simd/toint.hpp>

#endif
