//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ONE_ELSE_ZERO_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ONE_ELSE_ZERO_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-if_one_else_zero if_one_else_zero (function object)

    This function object conditionally returns @c 1 (respectively @c 0)
    if @c c is @ref [True](@ref constant-True) (respectively  @ref [False](@ref constant-False))

    @headerref{<boost/simd/function/if_one_else_zero.hpp>}

    @par Description

      @code
      Value if_one_else_zero(Value const& c);
      @endcode

    @par Example:

      @snippet if_one_else_zero.cpp if_one_else_zero

    @par Possible output:

      @snippet if_one_else_zero.txt if_one_else_zero

  **/

#include <boost/simd/function/scalar/if_one_else_zero.hpp>
#include <boost/simd/function/simd/if_one_else_zero.hpp>

#endif
