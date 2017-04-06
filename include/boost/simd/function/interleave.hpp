//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INTERLEAVE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INTERLEAVE_HPP_INCLUDED

namespace boost { namespace simd
{

  /*!
    @ingroup group-swar
    @defgroup real-interleave interleave (function object)

    This function object performs a complete interleaving of its arguments.

    interleave is guaranteed to be optimized as much as possible compared to using
    boost::simd::interleave_first and boost::simd::interleave_second in succession.

    @headerref{<boost/simd/function/interleave.hpp>}

    @par Description

      @code
      std::array<Value, 2> interleave(Value const& x, Value const& y);
      @endcode

    @par Semantic:
    For every parameters @c x and @c y of type @c T :
    @code
    std::array<T,2> r = interleave(x,y);
    @endcode

    is equivalent to :

    @code
    std::array<T,2> r = { interleave_first(x,y), interleave_second(x,y) };
    @endcode

  **/

} }

#include <boost/simd/function/simd/interleave.hpp>

#endif
