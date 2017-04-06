//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ASINPI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ASINPI_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-asinpi asinpi (function object)

    This function object returns the inverse sine in \f$\pi\f$ multiples.

    @headerref{<boost/simd/function/asinpi.hpp>}

    @par Description

      @code
      IEEEValue asinpi(IEEEValue const & x);
      @endcode

    @see asin, asind, sinpi

    @par Example:

      @snippet asinpi.cpp asinpi

    @par Possible output:

      @snippet asinpi.txt asinpi

  **/

#include <boost/simd/function/scalar/asinpi.hpp>
#include <boost/simd/function/simd/asinpi.hpp>

#endif
