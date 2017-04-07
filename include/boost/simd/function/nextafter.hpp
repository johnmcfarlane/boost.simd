//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEXTAFTER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEXTAFTER_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-nextafter nextafter (function object)

    Returns the next representable value of @c x in the direction of @c y

    @headerref{<boost/simd/function/nextafter.hpp>}

    @par Description

      @code
      Value nextafter(Value const& x, Value const& y);
      @endcode

    @par Semantic:

    @code
    auto r = nextafter(x, y);
    @endcode

    is similar to:

    @code
    if (y >  x)  r = next(x);
    else if (y == x)  r = x;
    else if (y <  x)  r = prev(x);
    @endcode

    @see ( %real ) [next](@ref real-next), [prev](@ref real-prev), [successor](@ref real-successor), [predecessor](@ref real-predecessor)

    @par Decorators

     - std_ calls std::nextafter


    @par Note
    C++11 standard library also defines @c nexttoward, but as (for SIMD considerations)
    @see next, prev, successor, predecessor

    @par Example:

      @snippet nextafter.cpp nextafter

    @par Possible output:

      @snippet nextafter.txt nextafter

  **/

#include <boost/simd/function/scalar/nextafter.hpp>
#include <boost/simd/function/simd/nextafter.hpp>

#endif
