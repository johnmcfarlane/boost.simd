//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TAN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TAN_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-tan tan (function object)

    This function object returns the tangent of the input in radians:
    \f$\sin(x)/\cos(x)\f$.

    @headerref{<boost/simd/function/tan.hpp>}

    @par Description

      @code
      IEEEValue tan(IEEEValue const& x);
      @endcode

    @par Note

      -  As most other trigonometric function tan can be called with a second
       optional parameter  which is a tag on speed and accuracy
       (see  [cos](@ref real-cos) for further details)

    @see ( %real ) [tand](@ref real-tand), [tanpi](@ref real-tanpi)

    @par Example:

      @snippet tan.cpp tan

    @par Possible output:

      @snippet tan.txt tan

  **/

#include <boost/simd/function/scalar/tan.hpp>
#include <boost/simd/function/simd/tan.hpp>

#endif
