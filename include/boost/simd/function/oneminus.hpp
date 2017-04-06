//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ONEMINUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ONEMINUS_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-oneminus oneminus (function object)

    This function object returns  one minus the entry.

    @headerref{<boost/simd/function/oneminus.hpp>}

    @par Description

      @code
      Value oneminus(Value const& x);
      @endcode

    @par Decorator

    _saturated_ is available,  but for unsigned integral types the saturated_
    function is merely  equivalent to `x == 0 ? 1 : 0`

    @par Notes
    Using `oneminus(x)` is similar to `1-x`

    @par Example:

      @snippet oneminus.cpp oneminus

    @par Possible output:

      @snippet oneminus.txt oneminus

  **/

#include <boost/simd/function/scalar/oneminus.hpp>
#include <boost/simd/function/simd/oneminus.hpp>

#endif
