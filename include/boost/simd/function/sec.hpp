//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SEC_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-sec sec (function object)

    This function object returns the secant of the angle in radian: \f$1/\cos(x)\f$.

    @headerref{<boost/simd/function/sec.hpp>}

    @par Description

      @code
      IEEEValue sec(IEEEValue const& x);
      @endcode

    @see ( %real ) [cos](@ref real-cos), [secd](@ref real-secd), [secpi](@ref real-secpi)

    @par Example:

      @snippet sec.cpp sec

    @par Possible output:

      @snippet sec.txt sec

  **/

#include <boost/simd/function/scalar/sec.hpp>
#include <boost/simd/function/simd/sec.hpp>

#endif
