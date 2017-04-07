//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-if_else if_else (function object)

    This function object conditionally returns @c t (respectively @c f) if @c c
    is  [True](@ref constant-True) (respectively   [False](@ref constant-False))

    @headerref{<boost/simd/function/if_else.hpp>}

    @par Description

      @code
      Value1 if_else(Value0 const& c, Value1 const& t, Value1 const& f);
      @endcode

    @par Example:

      @snippet if_else.cpp if_else

    @par Possible output:

      @snippet if_else.txt if_else

  **/

#include <boost/simd/function/scalar/if_else.hpp>
#include <boost/simd/function/simd/if_else.hpp>

#endif
