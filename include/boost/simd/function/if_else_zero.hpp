//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ELSE_ZERO_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ELSE_ZERO_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-if_else_zero if_else_zero (function object)

    This function object conditionally returns @c x (respectively @ref [Zero](@ref constant-Zero))
    if @c c is @ref [True](@ref constant-True) (respectively  @ref [False](@ref constant-False))

    @headerref{<boost/simd/function/if_else_zero.hpp>}

    @par Description

      @code
      Value1 if_else_zero(Value0 const& c, Value1 const& t);
      @endcode

    @par Example:

      @snippet if_else_zero.cpp if_else_zero

    @par Possible output:

      @snippet if_else_zero.txt if_else_zero

  **/

#include <boost/simd/function/scalar/if_else_zero.hpp>
#include <boost/simd/function/simd/if_else_zero.hpp>

#endif
