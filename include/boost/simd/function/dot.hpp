//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DOT_HPP_INCLUDED

  /*!
    @ingroup group-reduction
    @defgroup real-dot dot (function object)

    This function object returns the returns the dot product of the two arguments

    @headerref{<boost/simd/function/dot.hpp>}

    @par Description

      @code
      scalar_of_t<Value> dot(Value const& x, Value const& y);
      @endcode

    @par Example:

      @snippet edot.cpp dot

    @par Possible output:

      @snippet edot.txt dot

  **/

#include <boost/simd/function/scalar/dot.hpp>
#include <boost/simd/function/simd/dot.hpp>

#endif
