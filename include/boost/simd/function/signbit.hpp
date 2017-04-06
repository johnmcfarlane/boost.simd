//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIGNBIT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIGNBIT_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-signbit signbit (function object)

    This function object returns True or false according to the bit of sign set or not set.

    @headerref{<boost/simd/function/signbit.hpp>}

    @par Description

      @code
      as_logical_t<Value> signbit(Value const& x);
      @endcode

  **/

#include <boost/simd/function/scalar/is_negative.hpp>
#include <boost/simd/function/simd/signbit.hpp>

#endif
