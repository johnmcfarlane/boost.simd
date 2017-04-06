//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REM_2PI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REM_2PI_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-rem_2pi rem_2pi (function object)

    This function object returns the compute the remainder modulo \f$2\pi\f$.

    @headerref{<boost/simd/function/rem_2pi.hpp>}

    @par Description

      @code
      IEEEValue rem_2pi(IEEEValue const& x);
      @endcode

    @par Note

     - The result is in \f$[-\pi, \pi]\f$.

     - If the input is near \f$\pi\f$ the output can be \f$\pi\f$ or \f$-\pi\f$
      depending  on register disponibility if extended arithmetic is used.

    @par Example:

      @snippet rem_2pi.cpp rem_2pi

    @par Possible output:

      @snippet rem_2pi.txt rem_2pi

  **/

#include <boost/simd/function/scalar/rem_2pi.hpp>
#include <boost/simd/function/simd/rem_2pi.hpp>

#endif
