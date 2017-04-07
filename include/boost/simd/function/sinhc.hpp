//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINHC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINHC_HPP_INCLUDED

  /*!
    @ingroup group-hyperbolic
    @defgroup real-sinhc sinhc (function object)

    This function object returns the hyperbolic cardinal sine: \f$\sinh(x)/x\f$.

    @headerref{<boost/simd/function/sinhc.hpp>}

    @par Description

      @code
      IEEEValue sinhc(IEEEValue const& x);
      @endcode

    @see ( %real ) [cosh](@ref real-cosh), [sinh](@ref real-sinh)

    @par Example:

      @snippet sinhc.cpp sinhc

    @par Possible output:

      @snippet sinhc.txt sinhc


  **/

#include <boost/simd/function/scalar/sinhc.hpp>
#include <boost/simd/function/simd/sinhc.hpp>

#endif
