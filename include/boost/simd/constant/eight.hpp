//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_EIGHT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_EIGHT_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Eight Eight (function object)

  Generates a value of the chosen type equal to eight.

    @headerref{<boost/simd/constant/eight.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Eight();
        @endcode

    2.  @code
        template<typename T> auto Eight( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Eight constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Eight<T>();
    @endcode
    is equivalent to:
    @code
    T r = static_cast<T>(8);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Eight( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Eight<T>();
    @endcode

    @par Requirements
    - **T** models Vectorizable
  **/

#include <boost/simd/constant/scalar/eight.hpp>
#include <boost/simd/constant/simd/eight.hpp>

#endif
