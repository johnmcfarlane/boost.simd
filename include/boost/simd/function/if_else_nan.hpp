//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ELSE_NAN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ELSE_NAN_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-if_else_nan if_else_nan (function object)

    This function object conditionally returns @c x (respectively @ref [Nan](@ref constant-Nan))
    if @c c is @ref [True](@ref constant-True) (respectively  @ref [False](@ref constant-False))

    This is an alias of @ref [if_else_allbits](@ref real-if_else_allbits)

    @headerref{<boost/simd/function/if_else_nan.hpp>}

    @par Description

      @code
      Value1 if_else_nan(Value0 const& c, Value1 const& x);
      @endcode

    @par Example:

      @snippet if_else_nan.cpp if_else_nan

    @par Possible output:

      @snippet if_else_nan.txt if_else_nan

  **/

#include <boost/simd/function/scalar/if_else_allbits.hpp>
#include <boost/simd/function/simd/if_else_nan.hpp>

#endif
