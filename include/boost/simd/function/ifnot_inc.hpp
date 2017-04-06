//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFNOT_INC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOT_INC_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-ifnot_inc ifnot_inc (function object)

    This function object conditionally returns  @c x (respectively @c x+1)
    if @c c is @ref True (respectively  @ref False)

    @headerref{<boost/simd/function/ifnot_inc.hpp>}

    @par Description

      @code
      Value1 ifnot_inc(Value0 const& c, Value1 const& x);
      @endcode

    @par Example:

      @snippet ifnot_inc.cpp ifnot_inc

    @par Possible output:

      @snippet ifnot_inc.txt ifnot_inc

  **/

#include <boost/simd/function/scalar/ifnot_inc.hpp>
#include <boost/simd/function/simd/ifnot_inc.hpp>

#endif
