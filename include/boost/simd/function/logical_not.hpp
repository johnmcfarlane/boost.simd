//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_NOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_NOT_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-logical_not logical_not (function object)

    This function object returns the return the logical negation of the argument.

    Infix notation can be used with operator '!'

    @headerref{<boost/simd/function/logical_not.hpp>}

    @par Description

      @code
      as_logical_t<Value0> logical_not(Value0 const& x, Value1 const& y);
      @endcode

    @see ( %real ) [logical_notor](@ref real-logical_notor), [logical_xor](@ref real-logical_xor), [logical_andnot](@ref real-logical_andnot), [logical_notand](@ref real-logical_notand), [logical_ornot](@ref real-logical_ornot), [logical_and](@ref real-logical_and), [logical_or](@ref real-logical_or)

    @par Example:

      @snippet logical_not.cpp logical_not

    @par Possible output:

      @snippet logical_not.txt logical_not

  **/

#include <boost/simd/function/scalar/logical_not.hpp>
#include <boost/simd/function/simd/logical_not.hpp>

#endif
