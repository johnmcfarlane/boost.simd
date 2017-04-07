//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFNOT_DEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOT_DEC_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-ifnot_dec ifnot_dec (function object)

    This function object conditionally returns  @c x (respectively @c x-1)
    if @c c is @ref [True](@ref constant-True) (respectively  @ref [False](@ref constant-False))

    @headerref{<boost/simd/function/ifnot_dec.hpp>}

    @par Description

      @code
      Value1 ifnot_dec(Value0 const& c, Value1 const& x);
      @endcode

    @par Example:

      @snippet ifnot_dec.cpp ifnot_dec

    @par Possible output:

      @snippet ifnot_dec.txt ifnot_dec

  **/

#include <boost/simd/function/scalar/ifnot_dec.hpp>
#include <boost/simd/function/simd/ifnot_dec.hpp>

#endif
