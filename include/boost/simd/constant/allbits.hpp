//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_ALLBITS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_ALLBITS_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Allbits Allbits (function object)

    Generates a value of the chosen type which all bits are set to 1.

    @headerref{<boost/simd/constant/allbits.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Allbits();
        @endcode

    2.  @code
        template<typename T> auto Allbits( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Allbits constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Allbits<T>();
    @endcode
    is equivalent to:
       - if T is floating point:
         @code
         T r = Nan<T>();
         @endcode
       - otherwise:
         @code
         T r = T(~0);
         @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Allbits( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Allbits<T>();
    @endcode

    @par Requirements
    - **T** models Vectorizable
  **/

#include <boost/simd/constant/scalar/allbits.hpp>
#include <boost/simd/constant/simd/allbits.hpp>

#endif
