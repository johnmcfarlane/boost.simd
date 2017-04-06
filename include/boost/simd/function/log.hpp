//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOG_HPP_INCLUDED

  /*!
    @ingroup group-exponential
    @defgroup real-log log (function object)

    This function object returns the natural logarithm of its argument.

    @headerref{<boost/simd/function/log.hpp>}

    @par Description

      @code
      IEEEValue log(IEEEValue const& x);
      @endcode

    @par Decorators

      - std_ for floating entries calls @c std::log


    @par Note:

    - log(x) return Nan for negative entries (peculiarly Mzero
    for floating numbers).

    @see log10, log2, log1p

    @par Example:

      @snippet log.cpp log

    @par Possible output:

      @snippet log.txt log

  **/

#include <boost/simd/function/scalar/log.hpp>
#include <boost/simd/function/simd/log.hpp>

#endif
