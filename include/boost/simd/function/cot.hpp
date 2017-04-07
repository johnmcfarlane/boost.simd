//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COT_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-cot cot (function object)

    This function object returns the cotangent of the input in radian: \f$\cos(x)/\sin(x)\f$.

    @headerref{<boost/simd/function/cot.hpp>}

    @par Description

      @code
      IEEEValue cot(IEEEValue const& x);
      @endcode

    @par Note

      As most other trigonometric function cot can be called
      with a second optional parameter  which is a tag on speed and accuracy
      (see  [cos](@ref real-cos) for further details)

    @see ( %real ) [cos](@ref real-cos), [sin](@ref real-sin), [tan](@ref real-tan), [cotd](@ref real-cotd), [cotpi](@ref real-cotpi)

    @par Example:

      @snippet cot.cpp cot

    @par Possible output:

      @snippet cot.txt cot

  **/

#include <boost/simd/function/scalar/cot.hpp>
#include <boost/simd/function/simd/cot.hpp>

#endif
