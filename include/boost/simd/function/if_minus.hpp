//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_MINUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_MINUS_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-if_minus if_minus (function object)

    This function object conditionally returns @c x-y (respectively @c x)  if @c c is @ref [True](@ref constant-True)
    (respectively  @ref [False](@ref constant-False))

    @headerref{<boost/simd/function/if_minus.hpp>}

    @par Description

      @code
      Value1 if_minus(Value0 const& c, Value1 const& x, Value1 const& y);
      @endcode

    @par Example:

      @snippet if_minus.cpp if_minus

    @par Possible output:

      @snippet if_minus.txt if_minus

  **/

#include <boost/simd/function/scalar/if_minus.hpp>
#include <boost/simd/function/simd/if_minus.hpp>

#endif
