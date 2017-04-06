//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ATANH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ATANH_HPP_INCLUDED

  /*!
    @ingroup group-hyperbolic
    @defgroup real-atanh atanh (function object)

    This function object returns the hyperbolic tangent argument \f$\frac12\log\frac{1+x}{1-x}\f$

    @headerref{<boost/simd/function/atanh.hpp>}

    @par Description

      @code
      IEEEValue atanh(IEEEValue const& x);
      @endcode

    @see cosh, sinh, acosh, asinh, atanh, asech, acoth, acsch

    @par Example:

      @snippet atanh.cpp atanh

    @par Possible output:

      @snippet atanh.txt atanh


  **/

#include <boost/simd/function/scalar/atanh.hpp>
#include <boost/simd/function/simd/atanh.hpp>

#endif
