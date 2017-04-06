//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACSCPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACSCPI_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-acscpi acscpi (function object)

    This function object returns the inverse secant in \f$\pi\f$ multiples:
    \f$(1/\pi) \arcsin(1/x)\f$.

    @headerref{<boost/simd/function/acscpi.hpp>}

    @par Description

      @code
      IEEEValue acscpi(IEEEValue const & x);
      @endcode

    @see acsc,  acscd

    @par Example:

      @snippet acscpi.cpp acscpi

    @par Possible output:

      @snippet acscpi.txt acscpi

  **/

#include <boost/simd/function/scalar/acscpi.hpp>
#include <boost/simd/function/simd/acscpi.hpp>

#endif
