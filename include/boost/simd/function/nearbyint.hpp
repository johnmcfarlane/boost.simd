//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEARBYINT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEARBYINT_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-nearbyint nearbyint (function object)

    This function object computes the rounded to even value of its parameter.

    @headerref{<boost/simd/function/nearbyint.hpp>}

    @par Description

      @code
      Value nearbyint(Value const& x);
      @endcode

    @par Notes:
    - If x is \f$\pm\infty\f$, it is returned, unmodified
    - If x is \f$\pm0\f$, it is returned, unmodified
    - If x is NaN, NaN is returned

    - to even means that half integer values are rounded to the nearest
    even value.

    -  This function is in general faster than @ref round which do the rouding on
        half integer values away from zero.

    @see round, ceil, floor, trunc
  **/

#include <boost/simd/function/scalar/nearbyint.hpp>
#include <boost/simd/function/simd/nearbyint.hpp>

#endif
