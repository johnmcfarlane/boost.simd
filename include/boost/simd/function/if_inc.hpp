//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_INC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_INC_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-if_inc if_inc (function object)

    This function object conditionally returns @c x+1 (respectively @c x)
    if @c c is @ref [True](@ref constant-True) (respectively  @ref [False](@ref constant-False))

    @headerref{<boost/simd/function/if_inc.hpp>}

    @par Description

      @code
      Value1 if_inc(Value0 const& c, Value1 const& x);
      @endcode

    @par Example:

      @snippet if_inc.cpp if_inc

    @par Possible output:

      @snippet if_inc.txt if_inc

  **/

#include <boost/simd/function/scalar/if_inc.hpp>
#include <boost/simd/function/simd/if_inc.hpp>

#endif
