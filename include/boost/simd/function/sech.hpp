//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SECH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SECH_HPP_INCLUDED

  /*!
    @ingroup group-hyperbolic
    @defgroup real-sech sech (function object)

    This function object returns the hyperbolic secant: \f$1/\cosh(x)\f$.

    @headerref{<boost/simd/function/sech.hpp>}

    @par Description

      @code
      IEEEValue sech(IEEEValue const& x);
      @endcode

    @see cosh, sinh, tanh, csch, sinhcosh


    @par Example:

      @snippet sech.cpp sech

    @par Possible output:

      @snippet sech.txt sech

  **/

#include <boost/simd/function/scalar/sech.hpp>
#include <boost/simd/function/simd/sech.hpp>

#endif
