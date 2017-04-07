//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_ZERO_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_ZERO_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Zero Zero (function object)

    Generates a value of the chosen type which all bits are set to 1.

    @headerref{<boost/simd/constant/zero.hpp>}

    @par Description

    1.  @code
        template<typename T> auto zero();
        @endcode

    2.  @code
        template<typename T> auto zero( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Zero constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Zero<T>();
    @endcode
    is similar to:
    @code
    T r = T(0);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Zero( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Zero<T>();
    @endcode

    @par Requirements
    - **T** models Vectorizable
  **/

#include <boost/simd/constant/scalar/zero.hpp>
#include <boost/simd/constant/simd/zero.hpp>

#endif
