//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SBITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SBITS_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-sbits sbits (function object)

    This function object returns the signed integer value which has the bit pattern of the
    input

    @headerref{<boost/simd/function/sbits.hpp>}

    @par Description

      @code
      as_integer_t<Value> sbits(Value const& x);
      @endcode

    @par Example:

      @snippet sbits.cpp sbits

    @par Possible output:

      @snippet sbits.txt sbits

  **/

#include <boost/simd/function/scalar/sbits.hpp>
#include <boost/simd/function/simd/sbits.hpp>

#endif
