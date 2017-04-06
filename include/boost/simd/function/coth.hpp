//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COTH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COTH_HPP_INCLUDED

  /*!
    @ingroup group-hyperbolic
    @defgroup real-coth coth (function object)

    This unction object returns the hyperbolic cotangent:
    \f$(e^{x}+e^{-x})/(e^{x}-e^{-x})\f$

    @headerref{<boost/simd/function/coth.hpp>}

    @par Description

      @code
      IEEEValue coth(IEEEValue const& x);
      @endcode

    @see sinh, cosh, sinhcosh

    @par Example:

      @snippet coth.cpp coth

    @par Possible output:

      @snippet coth.txt coth

  **/

#include <boost/simd/function/scalar/coth.hpp>
#include <boost/simd/function/simd/coth.hpp>

#endif
