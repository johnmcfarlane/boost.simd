//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ATAN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ATAN_HPP_INCLUDED

  /*!
    @ingroup group-trigonometric
    @defgroup real-atan atan (function object)

    This function object returns the inverse tangent.

    @headerref{<boost/simd/function/atan.hpp>}

    @par Description

      @code
      IEEEValue atan(IEEEValue const& x);
      @endcode

    @par Decorators

     - std_ for floating entries  provides access to std::atan

    @par Note

      For every parameter of floating type `atan(x)`
      returns the arc @c r in the interval  \f$[-\pi/2, \pi/2[\f$
      such that <tt>tan(r) == x</tt>.

    @see ( %real ) [atan2](@ref real-atan2), [atand](@ref real-atand), [atanpi](@ref real-atanpi), [tan](@ref real-tan)

    @par Example:

      @snippet atan.cpp atan

    @par Possible output:

      @snippet atan.txt atan

  **/

#include <boost/simd/function/scalar/atan.hpp>
#include <boost/simd/function/simd/atan.hpp>

#endif
