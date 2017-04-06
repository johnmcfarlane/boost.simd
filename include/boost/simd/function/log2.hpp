//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOG2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOG2_HPP_INCLUDED

  /*!
    @ingroup group-exponential
    @defgroup real-log2 log2 (function object)

    This function object returns the base two logarithm of its argument.

    @headerref{<boost/simd/function/log2.hpp>}

    @par Description

      @code
      IEEEValue log2(IEEEValue const& x);
      @endcode

    @par Decorators

      - std_ for floating entries calls @c std::log2

    @see log10, log, log1p

    @par Example:

      @snippet log2.cpp log2

    @par Possible output:

      @snippet log2.txt log2

  **/

#include <boost/simd/function/scalar/log2.hpp>
#include <boost/simd/function/simd/log2.hpp>

#endif
