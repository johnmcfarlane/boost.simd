//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TWO_ADD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TWO_ADD_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-two_add two_add (function object)

    This function object computes two reals of the type of the inputs
    (in an std::pair) @c r0 and @c r1 such that:

    @headerref{<boost/simd/function/two_add.hpp>}

    @par Description

      @code
      std::pair<Value, Value> two_add(Value const& x, Value const& y);
      @endcode

    @par Example:

      @snippet two_add.cpp two_add

    @par Possible output:

      @snippet two_add.txt two_add


  **/

#include <boost/simd/function/scalar/two_add.hpp>
#include <boost/simd/function/simd/two_add.hpp>

#endif
