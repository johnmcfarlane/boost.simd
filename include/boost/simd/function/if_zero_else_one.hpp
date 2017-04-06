//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ZERO_ELSE_ONE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ZERO_ELSE_ONE_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-if_zero_else_one if_zero_else_one (function object)

    This function object conditionally returns  @c 0 (respectively @c 1)
    if @c c is @ref True (respectively  @ref False)

    @headerref{<boost/simd/function/if_zero_else_one.hpp>}

    @par Description

      @code
      Value if_zero_else_one(Value const& c);
      @endcode

    @par Example:

      @snippet if_zero_else_one.cpp if_zero_else_one

    @par Possible output:

      @snippet if_zero_else_one.txt if_zero_else_one

  **/

#include <boost/simd/function/scalar/if_zero_else_one.hpp>
#include <boost/simd/function/simd/if_zero_else_one.hpp>

#endif
