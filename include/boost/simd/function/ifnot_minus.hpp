//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFNOT_MINUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOT_MINUS_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-ifnot_minus ifnot_minus (function object)

    This function object conditionally returns  @c x (respectively @c x-y)
    if @c c is @ref True (respectively  @ref False)

    @headerref{<boost/simd/function/ifnot_minus.hpp>}

    @par Description

      @code
      Value1 ifnot_minus(Value0 const& c, Value1 const& x, Value1 const& y);
      @endcode

    @par Example:

      @snippet ifnot_minus.cpp ifnot_minus

    @par Possible output:

      @snippet ifnot_minus.txt ifnot_minus

  **/

#include <boost/simd/function/scalar/ifnot_minus.hpp>
#include <boost/simd/function/simd/ifnot_minus.hpp>

#endif
