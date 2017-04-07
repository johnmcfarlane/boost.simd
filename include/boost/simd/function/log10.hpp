//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOG10_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOG10_HPP_INCLUDED

  /*!
    @ingroup group-exponential
    @defgroup real-log10 log10 (function object)

    This function object returns the base ten logarithm of its argument.

    For integer input types @c log10 return the truncation of the real result.

    @headerref{<boost/simd/function/log10.hpp>}

    @par Description

      @code
      IEEEValue log10(IEEEValue const& x);
      @endcode

    @par Decorators

      - std_ for floating entries calls @c std::log10

    @see ( %real ) [log](@ref real-log), [log2](@ref real-log2), [log1p](@ref real-log1p)

    @par Example:

      @snippet log10.cpp log10

    @par Possible output:

      @snippet log10.txt log10

  **/

#include <boost/simd/function/scalar/log10.hpp>
#include <boost/simd/function/simd/log10.hpp>

#endif
