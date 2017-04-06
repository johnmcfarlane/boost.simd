//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SLICE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SLICE_HPP_INCLUDED

  /*!
    @ingroup group-swar
    @defgroup real-slice slice (function object)

    Type-preserving pack slicing

    This function object slices a simd::pack into two simd::packs of same type of half the size.

    @headerref{<boost/simd/function/slice.hpp>}

    @par Description

      @code
      std::array<ValueO, 2> slice(Value1 const& x);
      @endcode

    @par Semantic:

    For any value @c a of type @c T, the following code:

    @code
    pack<T, N> x;
    std::array<pack<T, N/2>, 2> res = slice(x);
    @endcode

    returns an array type which behaves so that:

    @code
    compare_equal(a, combine(c[0],c[1]));
    @endcode

    evaluates to @c true.

    @see combine, slice_low, slice_high
    @see combine, slice_low, slice_high
  **/

#include <boost/simd/function/simd/slice.hpp>

#endif
