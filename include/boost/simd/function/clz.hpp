//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CLZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CLZ_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-clz clz (function object)

    This function object returns  the bit count of leading zeros.

    @headerref{<boost/simd/function/clz.hpp>}

    @par Description

      @code
      as_integer_t<Value> clz(Value const& x);
      @endcode

    @see ( %real ) [ctz](@ref real-ctz), [popcnt](@ref real-popcnt)

    @par Example:

      @snippet clz.cpp clz

    @par Possible output:

      @snippet clz.txt clz

  **/

#include <boost/simd/function/scalar/clz.hpp>
#include <boost/simd/function/simd/clz.hpp>

#endif
