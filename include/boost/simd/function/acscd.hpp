//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACSCD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACSCD_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-acscd acscd (function object)

    This function object returns the inverse cosecant in degree:
    \f$(180/\pi) \arcsin(1/x)\f$.

    @headerref{<boost/simd/function/acscd.hpp>}

    @par Description

      @code
      IEEEValue acscd(IEEEValue const & x);
      @endcode

    @see acsc, accscpi

    @par Example:

      @snippet acscd.cpp acscd

    @par Possible output:

      @snippet acscd.txt acscd

  **/

#include <boost/simd/function/scalar/acscd.hpp>
#include <boost/simd/function/simd/acscd.hpp>

#endif
