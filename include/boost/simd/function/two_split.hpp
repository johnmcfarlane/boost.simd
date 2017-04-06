//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TWO_SPLIT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TWO_SPLIT_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-two_split two_split (function object)

    This function object computes two reals @c r0 and @c r1 (in an std::pair)
    such that:

    @headerref{<boost/simd/function/two_split.hpp>}

    @par Description

      @code
      std::pair<Value, Value> two_split(Value const& x);
      @endcode

    @par Example:

      @snippet two_split.cpp two_split

    @par Possible output:

      @snippet two_split.txt two_split

  **/

#include <boost/simd/function/scalar/two_split.hpp>
#include <boost/simd/function/simd/two_split.hpp>

#endif
