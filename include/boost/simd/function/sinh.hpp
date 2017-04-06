//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINH_HPP_INCLUDED

  /*!
    @ingroup group-hyperbolic
    @defgroup real-sinh sinh (function object)

    This function object returns the hyperbolic sine: \f$(e^{x}-e^{-x})/2\f$.

    @headerref{<boost/simd/function/sinh.hpp>}

    @par Description

      @code
      IEEEValue sinh(IEEEValue const& x);
      @endcode

    @see tanh, cosh, sech, csch, sinhcosh

    @par Example:

      @snippet sinh.cpp sinh

    @par Possible output:

      @snippet sinh.txt sinh
  **/

#include <boost/simd/function/scalar/sinh.hpp>
#include <boost/simd/function/simd/sinh.hpp>

#endif
