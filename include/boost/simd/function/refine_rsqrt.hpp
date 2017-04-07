//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REFINE_RSQRT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REFINE_RSQRT_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-refine_rsqrt refine_rsqrt (function object)

    This function object performs a Newton-Raphson step to improve precision of rsqrt estimate.

    This function can be used in conjunction with raw_(rsqrt)
    to add more precision to the estimates if their default
    precision is not enough.

    @headerref{<boost/simd/function/refine_rsqrt.hpp>}

    @par Description

      @code
      IEEEValue refine_rsqrt(IEEEValue const& x, IEEEValue const& est);
      @endcode

    @see ( %real ) [rec](@ref real-rec)

  **/

#include <boost/simd/function/scalar/refine_rsqrt.hpp>
#include <boost/simd/function/simd/refine_rsqrt.hpp>

#endif
