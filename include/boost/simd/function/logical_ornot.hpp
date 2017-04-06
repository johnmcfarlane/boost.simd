//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_ORNOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_ORNOT_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-logical_ornot logical_ornot (function object)

    This function object returns the logical or of the first
    argument and of the negation the second argument.

    @headerref{<boost/simd/function/logical_ornot.hpp>}

    @par Description

      @code
      as_logical_t<Value0> logical_ornot(Value0 const& x, Value1 const& y);
      @endcode

    @par Note

    - The result type is the logical type associated to the first argument.

    @see logical_not,  logical_xor, logical_andnot,  logical_notand,  logical_or, logical_and,  logical_notor

    @par Example:

      @snippet logical_ornot.cpp logical_ornot

    @par Possible output:

      @snippet logical_ornot.txt logical_ornot

  **/

#include <boost/simd/function/scalar/logical_ornot.hpp>
#include <boost/simd/function/simd/logical_ornot.hpp>

#endif
