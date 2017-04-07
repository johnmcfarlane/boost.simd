//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TAND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TAND_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-tand tand (function object)

    This function object returns the tangent of the input in degrees:
    \f$\sin(\pi x/180)/\cos(\pi x/180) \f$.

    @headerref{<boost/simd/function/tand.hpp>}

    @par Description

      @code
      IEEEValue tand(IEEEValue const& x);
      @endcode

    @par Note

      As most other trigonometric function tand can be called with a
      second optional parameter  which is a tag on speed and accuracy
      (see @ref cos for further details)

    @see ( %real ) [tan](@ref real-tan), [tanpi](@ref real-tanpi)

    @par Example:

      @snippet tand.cpp tand

    @par Possible output:

      @snippet tand.txt tand

  **/

#include <boost/simd/function/scalar/tand.hpp>
#include <boost/simd/function/simd/tand.hpp>

#endif
