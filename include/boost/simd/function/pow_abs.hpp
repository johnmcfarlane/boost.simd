//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_POW_ABS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_POW_ABS_HPP_INCLUDED

  /*!
    @ingroup group-exponential
    @defgroup real-pow_abs pow_abs (function object)

    This function object computes \f$|x|^y\f$.

    @headerref{<boost/simd/function/pow_abs.hpp>}

    @par Description

      @code
      IEEEValue pow_abs(IEEEValue const& x, IEEEValue const& y);
      @endcode

    @par Decorators

    - raw_  is faster but can be inaccurate.

    @see ( %real ) [pow](@ref real-pow), [abs](@ref real-abs)

    @par Example:

      @snippet pow_abs.cpp pow_abs

    @par Possible output:

      @snippet pow_abs.txt pow_abs

  **/

#include <boost/simd/function/scalar/pow_abs.hpp>
#include <boost/simd/function/simd/pow_abs.hpp>

#endif
