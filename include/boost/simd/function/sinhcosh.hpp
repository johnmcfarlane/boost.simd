//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINHCOSH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINHCOSH_HPP_INCLUDED

  /*!
    @ingroup group-hyperbolic
    @defgroup real-sinhcosh sinhcosh (function object)

    This function object computes simultaneously  and at lower cost
    the @c sinh and @c cosh of the input

    @headerref{<boost/simd/function/sinhcosh.hpp>}

    @par Description

      @code
      std::pair<IEEEValue, IEEEValue> sinhcosh(IEEEValue const& x);
      @endcode

    @see  sinh, cosh

    @par Example:

      @snippet sinhcosh.cpp sinhcosh

    @par Possible output:

      @snippet sinhcosh.txt sinhcosh

  **/

#include <boost/simd/function/scalar/sinhcosh.hpp>
#include <boost/simd/function/simd/sinhcosh.hpp>

#endif
