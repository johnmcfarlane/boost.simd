//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINMOD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINMOD_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-minmod minmod (function object)

    This function object computes the smallest of its parameter if they share the same sign,
    zero instead.

    @headerref{<boost/simd/function/minmod.hpp>}

    @par Description

      @code
      Value minmod(Value const& x, Value const& y);
      @endcode

    @par Notes

    Using `minmod(x, y)` is similar to `x*y > 0 ? min(x, y) : 0`

    @see ( %real ) [min](@ref real-min), [minnum](@ref real-minnum), [minnummag](@ref real-minnummag), [minmag](@ref real-minmag)

    @par Example:

      @snippet minmod.cpp minmod

    @par Possible output:

      @snippet minmod.txt minmod

  **/

#include <boost/simd/function/scalar/minmod.hpp>
#include <boost/simd/function/simd/minmod.hpp>

#endif
