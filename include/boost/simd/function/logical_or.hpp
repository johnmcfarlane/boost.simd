//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_OR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_OR_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-logical_or logical_or (function object)

    This function object returns the return the logical or of the two arguments

    Infix notation can be used with operator '||'

    @headerref{<boost/simd/function/logical_or.hpp>}

    @par Description

      @code
      as_logical_t<Value0> logical_or(Value0 const& x, Value1 const& y);
      @endcode

    @par Note

    - The result type is the logical type associated to the first argument.

    @see logical_not,  logical_xor, logical_andnot,  logical_notand,  logical_ornot, logical_and,  logical_notor

    @par Example:

      @snippet logical_or.cpp logical_or

    @par Possible output:

      @snippet logical_or.txt logical_or

  **/

#include <boost/simd/function/scalar/logical_or.hpp>
#include <boost/simd/function/simd/logical_or.hpp>

#endif
