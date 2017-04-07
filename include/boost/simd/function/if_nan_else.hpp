//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_NAN_ELSE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_NAN_ELSE_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-if_nan_else if_nan_else (function object)

    This function object conditionally returns @c Nan (respectively @c x)
    if @c c is @ref [True](@ref constant-True) (respectively  @ref [False](@ref constant-False))

    @headerref{<boost/simd/function/if_nan_else.hpp>}

    @par Description

      @code
      Value1 if_nan_else(Value0 const& c, Value1 const& x);
      @endcode

    @par Example:

      @snippet if_nan_else.cpp if_nan_else

    @par Possible output:

      @snippet if_nan_else.txt if_nan_else

  **/

#include <boost/simd/function/scalar/if_allbits_else.hpp>
#include <boost/simd/function/simd/if_nan_else.hpp>

#endif
