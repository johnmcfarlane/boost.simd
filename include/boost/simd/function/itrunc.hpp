//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ITRUNC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ITRUNC_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-itrunc itrunc (function object)

    Function object implementing itrunc capabilities

    Convert to integer by saturated truncation.

    This is an alias of saturated_(toint) (See @ref toint)

    @headerref{<boost/simd/function/itrunc.hpp>}

    @par Description

      @code
      Value itrunc(Value const& x);
      @endcode

    @see ( %real ) [ifix](@ref real-ifix)

  **/

#include <boost/simd/function/scalar/itrunc.hpp>
#include <boost/simd/function/simd/itrunc.hpp>

#endif
