//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_NOTOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_NOTOR_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-logical_notor logical_notor (function object)

    This function object returns the logical or of the negation of the
    first argument with the second argument

    @headerref{<boost/simd/function/logical_notor.hpp>}

    @par Description

      @code
      as_logical_t<Value0> logical_notor(Value0 const& x, Value1 const& y);
      @endcode

    @par Note

    - The result type is the logical type associated to the first argument.

    @see logical_not,  logical_xor, logical_andnot,  logical_notand,  logical_ornot, logical_and,  logical_or

    @par Example:

      @snippet logical_notor.cpp logical_notor

    @par Possible output:

      @snippet logical_notor.txt logical_notor

  **/

#include <boost/simd/function/scalar/logical_notor.hpp>
#include <boost/simd/function/simd/logical_notor.hpp>

#endif
