//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TWOTONMB_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TWOTONMB_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Twotonmb Twotonmb (function object)

    Generates  two to the number of mantissa bits.

    @headerref{<boost/simd/constant/twotonmb.hpp>}

    @par Description

    1.  @code
        template<typename T> auto Twotonmb();
        @endcode

    2.  @code
        template<typename T> auto Twotonmb( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Twotonmb constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Twotonmb<T>();
    @endcode
    is similar to:
    @code
    T r = pow(2, Nbmantissabits<T>());
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Twotonmb( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Twotonmb<T>();
    @endcode

    @par Requirements
    - **T** models Vectorizable
  **/

#include <boost/simd/constant/scalar/twotonmb.hpp>
#include <boost/simd/constant/simd/twotonmb.hpp>

#endif
