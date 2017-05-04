//==================================================================================================
/**
  @file
  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ABS_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ABS_HPP_INCLUDED

/*!
  @ingroup group-complex
  @defgroup complex-abs abs (function object)

  Returns the magnitude of a complex number.

  @headerref{<boost/simd/type/complex/function/abs.hpp>}

  @par Description

  @code
  IEEEValue abs(complex<IEEEValue> const& z);
  @endcode

  Returns the magnitude of the complex number `z` with no actual provision for limit cases.

  @par Supported decorators:
  - [pedantic_](@ref decorator-pedantic) : Adds support for infinites, NaNs and solves
    precision issues if real and imaginary parts have a large difference in magnitude.

  @par Associated functions
  - Real functions: [abs](@ref real-abs), [sqr_abs](@ref real-sqr_abs)
  - Complex functions: [sqr_abs](@ref complex-sqr_abs)

  @par Example
  @snippet c_abs.cpp abs

  @par Possible output
  @snippet c_abs.txt abs
**/

#include <boost/simd/function/abs.hpp>
#include <boost/simd/type/complex/function/impl/abs.hpp>

#endif
