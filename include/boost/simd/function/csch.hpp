//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_CSCH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CSCH_HPP_INCLUDED

  /*!
    @ingroup group-hyperbolic
    @defgroup real-csch csch (function object)

    This function object returns the hyperbolic cosecant: \f$1/\sinh(1/x)\f$.

    @headerref{<boost/simd/function/csch.hpp>}

    @par Description

      @code
      IEEEValue csch(IEEEValue const& x);
      @endcode

    @see ( %real ) [sinh](@ref real-sinh), [tanh](@ref real-tanh), [sech](@ref real-sech), [csch](@ref real-csch), [sinhcosh](@ref real-sinhcosh)

    @par Example:

      @snippet csch.cpp csch

    @par Possible output:

      @snippet csch.txt csch
  **/

#include <boost/simd/function/scalar/csch.hpp>
#include <boost/simd/function/simd/csch.hpp>

#endif
