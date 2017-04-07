//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOG1P_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOG1P_HPP_INCLUDED

  /*!
    @ingroup group-exponential
    @defgroup real-log1p log1p (function object)

    This function object computes \f$\log(1+x)\f$ with good accuracy even for small
    \f$x\f$ values.

    @headerref{<boost/simd/function/log1p.hpp>}

    @par Description

      @code
      IEEEValue log1p(IEEEValue const& x);
      @endcode

    @par Decorators

      - std_ for floating entries calls @c std::log1p

    @see ( %real ) [log](@ref real-log), [exp](@ref real-exp), [expm1](@ref real-expm1)

    @par Example:

      @snippet log1p.cpp log1p

    @par Possible output:

      @snippet log1p.txt log1p

  **/

#include <boost/simd/function/scalar/log1p.hpp>
#include <boost/simd/function/simd/log1p.hpp>

#endif
