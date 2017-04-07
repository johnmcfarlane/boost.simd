//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINIMUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINIMUM_HPP_INCLUDED

  /*!
    @ingroup group-reduction
    @defgroup real-minimum minimum (function object)

   This function object returns the smallest element of the argument

    @headerref{<boost/simd/function/minimum.hpp>}

    @par Description

      @code
      scalar_of_t<Value> minimum(Value const& x);
      @endcode

    @see ( %real ) [maximum](@ref real-maximum)

    @par Example:

      @snippet minimum.cpp minimum

    @par Possible output:

      @snippet minimum.txt minimum

  **/

#include <boost/simd/function/scalar/minimum.hpp>
#include <boost/simd/function/simd/minimum.hpp>

#endif
