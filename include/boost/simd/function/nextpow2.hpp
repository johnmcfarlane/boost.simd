//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEXTPOW2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEXTPOW2_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-nextpow2 nextpow2 (function object)

    This function object returns the smallest integer n such that
    `saturated_(abs)(x)` is less or equal to \f$2^n\f$

    @headerref{<boost/simd/function/nextpow2.hpp>}

    @par Description

      @code
      as_integer_t<Value> nextpow2(Value const& x);
      @endcode

    @par Example:

      @snippet nextpow2.cpp nextpow2

    @par Possible output:

      @snippet nextpow2.txt nextpow2

  **/

#include <boost/simd/function/scalar/nextpow2.hpp>
#include <boost/simd/function/simd/nextpow2.hpp>

#endif
