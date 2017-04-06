//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITWISE_NOTAND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_NOTAND_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-bitwise_notand bitwise_notand (function object)

    This function object computes the bitwise not and of its parameters.

    The result type is the one of the first operand.

    @headerref{<boost/simd/function/bitwise_notand.hpp>}

    @par Description

      @code
      Value0 bitwise_notand(Value0 const& x, Value1 const& y);
      @endcode

    @par Example:

      @snippet bitwise_notand.cpp bitwise_notand

    @par Possible output:

      @snippet bitwise_notand.txt bitwise_notand

  **/

#include <boost/simd/function/scalar/bitwise_notand.hpp>
#include <boost/simd/function/simd/bitwise_notand.hpp>

#endif
