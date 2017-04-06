//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TENPOWER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TENPOWER_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-tenpower tenpower (function object)

    Function object implementing tenpower capabilities

    Returns \f$10^n\f$ in the floating type associated to
    the integral type of parameter n

    @headerref{<boost/simd/function/tenpower.hpp>}

    @par Description

      @code
      Value tenpower(IntegerValue const& n);
      @endcode

    @par Note:

    This function is not defined for floating entries and intended to be used for
    small integer values.

    @see exp10

    @par Example:

      @snippet tenpower.cpp tenpower

    @par Possible output:

      @snippet tenpower.txt tenpower
  **/

#include <boost/simd/function/scalar/tenpower.hpp>
#include <boost/simd/function/simd/tenpower.hpp>

#endif
