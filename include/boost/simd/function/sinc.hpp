//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINC_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-sinc sinc (function object)

    This function object returns the Computes the sinus cardinal value of its parameter,
    i.e. \f$\sin(x)/x\f$.

    @headerref{<boost/simd/function/sinc.hpp>}

    @par Description

      @code
      IEEEValue sinc(IEEEValue const& x);
      @endcode

    @see sin, sincpi, sinhc

    @par Example:

      @snippet sinc.cpp sinc

    @par Possible output:

      @snippet sinc.txt sinc

  **/

#include <boost/simd/function/scalar/sinc.hpp>
#include <boost/simd/function/simd/sinc.hpp>

#endif
