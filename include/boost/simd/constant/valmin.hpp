//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_VALMIN_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_VALMIN_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Valmin Valmin (function object)

    Generates the minimum finite representable value of the given type.

    @headerref{<boost/simd/constant/valmin.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Valmin();
        @endcode

    2.  @code
        template<typename T> auto Valmin( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Valmin constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Valmin<T>();
    @endcode
    return the minimum finite representable value for this type.

    2.  A value of type @c T so that:
    @code
    T x, r = Valmin( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Valmin<T>();
    @endcode

    @par Requirements
    - **T** models Vectorizable
  **/

#include <boost/simd/constant/scalar/valmin.hpp>
#include <boost/simd/constant/simd/valmin.hpp>

#endif
