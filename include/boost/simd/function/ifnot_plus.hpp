//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFNOT_PLUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOT_PLUS_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-ifnot_plus ifnot_plus (function object)

    This function object conditionally returns  @c x (respectively @c x+y)
    if @c c is @ref True (respectively  @ref False)

    @headerref{<boost/simd/function/ifnot_plus.hpp>}

    @par Description

      @code
      Value1 ifnot_plus(Value0 const& c, Value1 const& x, Value1 const& y);
      @endcode

    @par Example:

      @snippet ifnot_plus.cpp ifnot_plus

    @par Possible output:

      @snippet ifnot_plus.txt ifnot_plus

  **/

#include <boost/simd/function/scalar/ifnot_plus.hpp>
#include <boost/simd/function/simd/ifnot_plus.hpp>

#endif
