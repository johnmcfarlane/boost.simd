//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REFINE_REC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REFINE_REC_HPP_INCLUDED

  /*!
    @ingroup group-arithmetic
    @defgroup real-refine_rec refine_rec (function object)

    This function object performs a Newton-Raphson step to improve precision of a reciprocate estimate.

    This function can be used in conjunction with raw_(rec)
    to add more precision to the estimates if their default
    precision is not enough.

    @headerref{<boost/simd/function/refine_rec.hpp>}

    @par Description

      @code
      IEEEValue refine_rec(IEEEValue const& x, IEEEValue const& est);
      @endcode

    @see rec

  **/

#include <boost/simd/function/scalar/refine_rec.hpp>
#include <boost/simd/function/simd/refine_rec.hpp>

#endif
