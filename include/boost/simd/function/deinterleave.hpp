//==================================================================================================
/*!
  @file
    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEINTERLEAVE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEINTERLEAVE_HPP_INCLUDED

  /*!
    @ingroup group-swar
    @defgroup real-deinterleave deinterleave (function object)

    This function object performs a complete deinterleaving of its arguments.

    deinterleave is guaranteed to be optimized as much as possible compared to using
    boost::simd::deinterleave_first and boost::simd::deinterleave_second in succession.

    @headerref{<boost/simd/function/deinterleave.hpp>}

    @par Description

      @code
      std::array<Value, 2> deinterleave(Value const& x, Value const& y);
      @endcode

    @par Semantic:
    For every parameters @c x and @c y of type @c T :
    @code
    std::array<T,2> r = deinterleave(x,y);
    @endcode
    is equivalent to :
    @code
    std::array<T,2> r = { deinterleave_first(x,y), deinterleave_second(x,y) };
    @endcode

  **/

#include <boost/simd/function/simd/deinterleave.hpp>

#endif
