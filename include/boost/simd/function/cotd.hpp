//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COTD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COTD_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-cotd cotd (function object)

    This function object returns the cotangent of input in degree:
    \f$\cos(\pi x/180)/\sin(\pi x/180)\f$.

    @headerref{<boost/simd/function/cotd.hpp>}

    @par Description

      @code
      IEEEValue cotd(IEEEValue const& x);
      @endcode

    @par Note

      As most other trigonometric function cotd can be called
      with a second optional parameter  which is a tag on speed
      and accuracy (see @ref cos for further details)

    @see ( %real ) [cos](@ref real-cos), [sin](@ref real-sin), [tan](@ref real-tan), [cot](@ref real-cot), [cotpi](@ref real-cotpi)

    @par Example:

      @snippet cotd.cpp cotd

    @par Possible output:

      @snippet cotd.txt cotd

  **/

#include <boost/simd/function/scalar/cotd.hpp>
#include <boost/simd/function/simd/cotd.hpp>

#endif
