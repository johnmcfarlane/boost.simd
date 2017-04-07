//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ZERO_ELSE_ALLBITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ZERO_ELSE_ALLBITS_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-if_zero_else_allbits if_zero_else_allbits (function object)

    This function object conditionally returns  @c 0 (respectively @ref [Allbits](@ref constant-Allbits))
    if @c c is @ref [True](@ref constant-True) (respectively  @ref [False](@ref constant-False))

    This is an alias of @ref [genmaskc](@ref real-genmaskc)

    @headerref{<boost/simd/function/if_zero_else_allbits.hpp>}

    @par Description

      @code

      @endcode

    @par Example:

      @snippet if_zero_else_allbits.cpp if_zero_else_allbits

    @par Possible output:

      @snippet if_zero_else_allbits.txt if_zero_else_allbits

  **/

#include <boost/simd/function/scalar/genmaskc.hpp>
#include <boost/simd/function/simd/if_zero_else_allbits.hpp>

#endif
