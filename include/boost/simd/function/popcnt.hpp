//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_POPCNT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POPCNT_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-popcnt popcnt (function object)

    This function object returns the number of set bits in the input.

    @headerref{<boost/simd/function/popcnt.hpp>}

    @par Description

      @code
      as_integer_t<Value> popcnt(Value const& x);
      @endcode

    @see  clz, ctz



    @par Example:

      @snippet popcnt.cpp popcnt

    @par Possible output:

      @snippet popcnt.txt popcnt

  **/

#include <boost/simd/function/scalar/popcnt.hpp>
#include <boost/simd/function/simd/popcnt.hpp>

#endif
