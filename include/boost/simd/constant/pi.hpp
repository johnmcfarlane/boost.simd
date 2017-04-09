//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_PI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_PI_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Pi Pi (function object)

    Generates value \f$\pi\f$ that is the half length of a circle of radius one
    ... in normal temperature and pressure conditions.

    @headerref{<boost/simd/constant/pi.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Pi();
        @endcode

    2.  @code
        template<typename T> auto Pi( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Pi constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Pi<T>();
    @endcode
    is similar to:
    @code
    T r = T(4*atan(1));
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Pi( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Pi<T>();
    @endcode

    @par Requirements
    - **T** models Vectorizable
  **/

#include <boost/simd/constant/scalar/pi.hpp>
#include <boost/simd/constant/simd/pi.hpp>

#endif
