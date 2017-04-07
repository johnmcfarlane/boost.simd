//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_DEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_DEC_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-if_dec if_dec (function object)

    This function object conditionally returns @c x-1 (respectively @c x)
    if @c c is @ref [True](@ref constant-True) (respectively  @ref [False](@ref constant-False))

    @headerref{<boost/simd/function/if_dec.hpp>}

    @par Description

      @code
      Value1 if_dec(Value0 const& c, Value1 const& x);
      @endcode

    @par Example:

      @snippet if_dec.cpp if_dec

    @par Possible output:

      @snippet if_dec.txt if_dec

  **/

#include <boost/simd/function/scalar/if_dec.hpp>
#include <boost/simd/function/simd/if_dec.hpp>

#endif
