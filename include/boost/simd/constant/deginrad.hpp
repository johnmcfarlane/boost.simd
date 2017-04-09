//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEGINRAD_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEGINRAD_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Deginrad Deginrad (function object)

    Constant radian in degree multiplier, \f$\frac{180}\pi\f$.

    @headerref{<boost/simd/constant/deginrad.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Deginrad();
        @endcode

    2.  @code
        template<typename T> auto Deginrad( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Deginrad constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Deginrad<T>();
    @endcode
    is similar to:
    @code
    T r = Ratio<T, 180>()/Pi<T>() ;
    @endcode
    @see  inrad, indeg, Radindeg, Radindegr, Ratio

    2.  A value of type @c T so that:
    @code
    T x, r = Deginrad( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Deginrad<T>();
    @endcode

    @par Requirements
    - **T** models Vectorizable
  **/

#include <boost/simd/constant/scalar/deginrad.hpp>
#include <boost/simd/constant/simd/deginrad.hpp>

#endif
