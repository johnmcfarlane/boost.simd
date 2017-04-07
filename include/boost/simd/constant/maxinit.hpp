//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_MAXINIT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_MAXINIT_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Maxinit Maxinit (function object)

    Generates a value of the chosen type which all bits are set to 1.

    @headerref{<boost/simd/constant/maxinit.hpp>}

    @par Description

    1.  @code
        template<typename T> auto maxinit();
        @endcode

    2.  @code
        template<typename T> auto maxinit( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Maxinit constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Maxinit<T>();
    @endcode


    2.  A value of type @c T so that:
    @code
    T x, r = Maxinit( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Maxinit<T>();
    @endcode

    @par Requirements
    - **T** models Vectorizable
  **/

#include <boost/simd/constant/scalar/maxinit.hpp>
#include <boost/simd/constant/simd/maxinit.hpp>

#endif
