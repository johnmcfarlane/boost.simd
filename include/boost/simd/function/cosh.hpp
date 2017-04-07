//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COSH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COSH_HPP_INCLUDED

  /*!
    @ingroup group-hyperbolic
    @defgroup real-cosh cosh (function object)

    This function object returns the hyperbolic cosine: \f$(e^{x}+e^{-x})/2\f$.

    @headerref{<boost/simd/function/cosh.hpp>}

    @par Description

      @code
      IEEEValue cosh(IEEEValue const& x);
      @endcode

    @see ( %real ) [sinh](@ref real-sinh), [tanh](@ref real-tanh), [sech](@ref real-sech), [csch](@ref real-csch), [sinhcosh](@ref real-sinhcosh)

    @par Example:

      @snippet cosh.cpp cosh

    @par Possible output:

      @snippet cosh.txt cosh
  **/

#include <boost/simd/function/scalar/cosh.hpp>
#include <boost/simd/function/simd/cosh.hpp>

#endif
