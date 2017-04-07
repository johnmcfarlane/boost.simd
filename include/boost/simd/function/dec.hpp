//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEC_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-dec dec (function object)

    This function object returns  its parameter decremented by 1.

    @headerref{<boost/simd/function/dec.hpp>}

    @par Description

      @code
      Value dec(Value const& x);
      @endcode

    @par Decorators

    - saturated_ ensures that @c saturated_(dec)(x) will never be
      strictly greater than @c x,
      avoiding the wrap around from  [Valmin](@ref constant-Valmin) to  [Valmax](@ref constant-Valmax) with integer types

    @see ( %real ) [inc](@ref real-inc), [minus](@ref real-minus)

    @par Example:

      @snippet dec.cpp dec

    @par Possible output:

      @snippet dec.txt dec
  **/

#include <boost/simd/function/scalar/dec.hpp>
#include <boost/simd/function/simd/dec.hpp>

#endif
