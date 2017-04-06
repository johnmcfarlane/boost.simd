//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXP10_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXP10_HPP_INCLUDED

  /*!
    @ingroup group-exponential
    @defgroup real-exp10 exp10 (function object)

    This function object returns the base ten exponential of its argument: \f$10^{x}\f$

    @headerref{<boost/simd/function/exp10.hpp>}

    @par Description

      @code
      IEEEValue exp10(IEEEValue const& x);
      @endcode

    @par Note:

    provisions are made for obtaining a flint result from a flint argument.

    @see exp2, exp, pow


    @par Example:

      @snippet exp10.cpp exp10

    @par Possible output:

      @snippet exp10.txt exp10

  **/

#include <boost/simd/function/scalar/exp10.hpp>
#include <boost/simd/function/simd/exp10.hpp>

#endif
