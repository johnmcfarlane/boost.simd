//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TANH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TANH_HPP_INCLUDED

  /*!
    @ingroup group-hyperbolic
    @defgroup real-tanh tanh (function object)

    This function object returns the hyperbolic tangent: \f$\sinh(x)/\cosh(x)\f$.

    @headerref{<boost/simd/function/tanh.hpp>}

    @par Description

      @code
      IEEEValue tanh(IEEEValue const& x);
      @endcode

    @see ( %real ) [sinh](@ref real-sinh), [cosh](@ref real-cosh), [sech](@ref real-sech), [csch](@ref real-csch), [sinhcosh](@ref real-sinhcosh)

    @par Example:

      @snippet tanh.cpp tanh

    @par Possible output:

      @snippet tanh.txt tanh
  **/

#include <boost/simd/function/scalar/tanh.hpp>
#include <boost/simd/function/simd/tanh.hpp>

#endif
