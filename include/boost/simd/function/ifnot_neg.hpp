//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFNOT_NEG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOT_NEG_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-ifnot_neg ifnot_neg (function object)

    This function object conditionally returns -x if @c c is  [False](@ref constant-False) and x otherwise.

    @headerref{<boost/simd/function/ifnot_neg.hpp>}

    @par Description

      @code
      Value1 ifnot_neg(Value0 const& c, Value1 const& x);
      @endcode

    @par Example:

      @snippet negifnot.cpp negifnot

    @par Possible output:

      @snippet negifnot.txt negifnot

  **/

#include <boost/simd/function/scalar/ifnot_neg.hpp>
#include <boost/simd/function/simd/ifnot_neg.hpp>

#endif
