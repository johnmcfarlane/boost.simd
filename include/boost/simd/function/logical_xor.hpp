//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_XOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_XOR_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-logical_xor logical_xor (function object)

    This function object returns the logical xor of the first argument
    and of the second argument.

    @headerref{<boost/simd/function/logical_xor.hpp>}

    @par Description

      @code
      as_logical_t<Value0> logical_xor(Value0 const& x, Value1 const& y);
      @endcode

    @par Note

    - The result type is the logical type associated to the first argument.

    @see logical_not,  logical_and, logical_andnot,  logical_notand,  logical_or, logical_ornot,  logical_notor

    @par Example:

      @snippet logical_xor.cpp logical_xor

    @par Possible output:

      @snippet logical_xor.txt logical_xor

  **/

#include <boost/simd/function/scalar/logical_xor.hpp>
#include <boost/simd/function/simd/logical_xor.hpp>

#endif
