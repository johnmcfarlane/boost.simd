//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CUMSUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CUMSUM_HPP_INCLUDED

  /*!
    @ingroup group-reduction
    @defgroup real-cumsum cumsum (function object)

    This function object returns the cumulate sum of the argument elements

    @headerref{<boost/simd/function/cumsum.hpp>}

    @par Description

      @code
      Value cumsum(Value const& x);
      @endcode

    @see cumprod, cummin, cummax

    @par Example:

      @snippet cumsum.cpp cumsum

    @par Possible output:

      @snippet cumsum.txt cumsum

  **/

#include <boost/simd/function/scalar/cumsum.hpp>
#include <boost/simd/function/simd/cumsum.hpp>

#endif
