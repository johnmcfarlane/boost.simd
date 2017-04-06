//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TWO_PROD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TWO_PROD_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-two_prod two_prod (function object)

    This function object computes two reals of the type of the inputs
    (in an std::pair)  @c r0 and @c r1 such that:

    @headerref{<boost/simd/function/two_prod.hpp>}

    @par Description

      @code
      std::pair<Value, Value> two_prod(Value const& x, Value const& y);
      @endcode

    @par Example:

      @snippet two_prod.cpp two_prod

    @par Possible output:

      @snippet two_prod.txt two_prod


  **/

#include <boost/simd/function/scalar/two_prod.hpp>
#include <boost/simd/function/simd/two_prod.hpp>

#endif
