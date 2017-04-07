//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_GREATESTNONINTEGER_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_GREATESTNONINTEGER_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Greatestnoninteger Greatestnoninteger (function object)

    Generates a value of the chosen type which all bits are set to 1.

    @headerref{<boost/simd/constant/greatestnoninteger.hpp>}

    @par Description

    1.  @code
        template<typename T> auto greatestnoninteger();
        @endcode

    2.  @code
        template<typename T> auto greatestnoninteger( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Greatestnoninteger constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Greatestnoninteger<T>();
    @endcode
    is similar to:
    @code
    if T is integral
      r = 0
    else if T is double
      r = 4503599627370495.5
    else if T is float
      r = 8388607.5f
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Greatestnoninteger( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Greatestnoninteger<T>();
    @endcode

    @par Requirements
    - **T** models Vectorizable
  **/

#include <boost/simd/constant/scalar/greatestnoninteger.hpp>
#include <boost/simd/constant/simd/greatestnoninteger.hpp>

#endif
