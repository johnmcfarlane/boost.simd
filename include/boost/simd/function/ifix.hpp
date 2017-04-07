//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFIX_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFIX_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-ifix ifix (function object)

    This function object convert to integer by saturated truncation.

    This is an alias of saturated_(toint) (See  [toint](@ref real-toint))

    @headerref{<boost/simd/function/ifix.hpp>}

    @par Description

      @code
      Value ifix(Value const& x);
      @endcode

    @par Example:

      @snippet ifix.cpp ifix

    @par Possible output:

      @snippet ifix.txt ifix


  **/

#include <boost/simd/function/scalar/ifix.hpp>
#include <boost/simd/function/simd/ifix.hpp>

#endif
