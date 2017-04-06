//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACSC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACSC_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-acsc acsc (function object)

    This function object returns the inverse cosecant in radian: \f$\arcsin(1/x)\f$.

    @headerref{<boost/simd/function/acsc.hpp>}

    @par Description

      @code
      IEEEValue acsc(IEEEValue const & x);
      @endcode

    @see acscd, acscpi, asin, asin, sin, rec

    @par Example:

      @snippet acsc.cpp acsc

    @par Possible output:

      @snippet acsc.txt acsc

  **/

#include <boost/simd/function/scalar/acsc.hpp>
#include <boost/simd/function/simd/acsc.hpp>

#endif
