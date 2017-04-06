//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACOSH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACOSH_HPP_INCLUDED

  /*!
    @ingroup group-hyperbolic
    @defgroup real-acosh acosh (function object)

    This function object returns the hyperbolic cosine argument: \f$\log(x+\sqrt{x^2-1})\f$.

    @headerref{<boost/simd/function/acosh.hpp>}

    @par Description

      @code
      IEEEValue acosh(IEEEValue const & x);
      @endcode

    @see cosh, sinh,  acsch, asinh, atanh, asech, acoth, acsch


    @par Example:

      @snippet acosh.cpp acosh

    @par Possible output:

      @snippet acosh.txt acosh

  **/

#include <boost/simd/function/scalar/acosh.hpp>
#include <boost/simd/function/simd/acosh.hpp>

#endif
