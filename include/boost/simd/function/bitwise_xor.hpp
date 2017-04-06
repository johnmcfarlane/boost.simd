//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITWISE_XOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_XOR_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-bitwise_xor bitwise_xor (function object)

    This function object returns the return the bitwise xor of the two parameters

    The result type is the one of the first operand.

    Infix notation can be used with operator '^',
    but this will not work in scalar mode if any
    operand is floating point because of C++ limitations.

    @headerref{<boost/simd/function/bitwise_xor.hpp>}

    @par Description

      @code
      Value0 bitwise_xor(Value0 const& x, Value1 const& y);
      @endcode

    @par Example:

      @snippet bitwise_xor.cpp bitwise_xor

    @par Possible output:

      @snippet bitwise_xor.txt bitwise_xor

  **/

#include <boost/simd/function/scalar/bitwise_xor.hpp>
#include <boost/simd/function/simd/bitwise_xor.hpp>

#endif
