//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_ANDNOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_ANDNOT_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-logical_andnot logical_andnot (function object)

    This function object returns the logical and of the first argument and of
    the logical negation of the second argument.

    @headerref{<boost/simd/function/logical_andnot.hpp>}

    @par Description

      @code
      as_logical_t<Value0> logical_andnot(Value0 const& x, Value1 const& y);
      @endcode

    @par Note

    - The result type is the logical type associated to the first argument.

    @par Example:

      @snippet logical_andnot.cpp logical_andnot

    @par Possible output:

      @snippet logical_andnot.txt logical_andnot

  **/

#include <boost/simd/function/scalar/logical_andnot.hpp>
#include <boost/simd/function/simd/logical_andnot.hpp>

#endif
