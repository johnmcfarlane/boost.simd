//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TRUNC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TRUNC_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-trunc trunc (function object)

    This function object computes the truncation toward  [Zero](@ref constant-Zero)
    of its parameter.

    @headerref{<boost/simd/function/trunc.hpp>}

    @par Description

      @code
      Value trunc(Value const& x);
      @endcode

    @par Decorators

       - std_ for floating entries call std::trunc

    @par Notes
      - the call to `trunc(x)` is similar to `sign(x)*floor(abs(x))`

      - For floating point number it is also one of the two ouputs of
        the  [modf](@ref real-modf) function.
        And we have:
    @see ( %real ) [abs](@ref real-abs), [frac](@ref real-frac), [floor](@ref real-floor), [sign](@ref real-sign), [modf](@ref real-modf), [itrunc](@ref real-itrunc)

    @par Example:

      @snippet trunc.cpp trunc

    @par Possible output:

      @snippet trunc.txt trunc

  **/

#include <boost/simd/function/scalar/trunc.hpp>
#include <boost/simd/function/simd/trunc.hpp>

#endif
