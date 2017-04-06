//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_NOTAND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_NOTAND_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-logical_notand logical_notand (function object)

    This function object returns the logical and of the negation of the
    first argument with the second argument

    @headerref{<boost/simd/function/logical_notand.hpp>}

    @par Description

      @code
      as_logical_t<Value0> logical_notand(Value0 const& x, Value1 const& y);
      @endcode

    @par Note

    - The result type is the logical type associated to the first argument.

    @see logical_not,  logical_xor, logical_andnot,  logical_notor,  logical_ornot, logical_and,  logical_or

    @par Example:

      @snippet logical_notand.cpp logical_notand

    @par Possible output:

      @snippet logical_notand.txt logical_notand

  **/

#include <boost/simd/function/scalar/logical_notand.hpp>
#include <boost/simd/function/simd/logical_notand.hpp>

#endif
