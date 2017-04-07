//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_AND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_AND_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-logical_and logical_and (function object)

    This function object returns the logical and of its two parameters.

    Infix notation can be used with operator '&&'.

    @headerref{<boost/simd/function/logical_and.hpp>}

    @par Description

      @code
      as_logical_t<Value0> logical_and(Value0 const& x, Value1 const& y);
      @endcode

    @par Note

    - The result type is the logical type associated to the first argument.

    @see ( %real ) [logical_not](@ref real-logical_not), [logical_xor](@ref real-logical_xor), [logical_andnot](@ref real-logical_andnot), [logical_notand](@ref real-logical_notand), [logical_or](@ref real-logical_or), [logical_ornot](@ref real-logical_ornot), [logical_notor](@ref real-logical_notor)

    @par Example:

      @snippet logical_and.cpp logical_and

    @par Possible output:

      @snippet logical_and.txt logical_and

  **/

#include <boost/simd/function/scalar/logical_and.hpp>
#include <boost/simd/function/simd/logical_and.hpp>

#endif
