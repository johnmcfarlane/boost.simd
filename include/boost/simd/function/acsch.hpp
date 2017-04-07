//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ACSCH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ACSCH_HPP_INCLUDED

  /*!
    @ingroup group-hyperbolic
    @defgroup real-acsch acsch (function object)

    This function object returns the hyperbolic cosecant argument
    \f$\mathop{\textrm{asinh}}(1/x)\f$

    @headerref{<boost/simd/function/acsch.hpp>}

    @par Description

      @code
      IEEEValue acsch(IEEEValue const & x);
      @endcode

    @see ( %real ) [cosh](@ref real-cosh), [sinh](@ref real-sinh), [acosh](@ref real-acosh), [asinh](@ref real-asinh), [atanh](@ref real-atanh), [asech](@ref real-asech), [acoth](@ref real-acoth), [atanh](@ref real-atanh)

    @par Example:

      @snippet acsch.cpp acsch

    @par Possible output:

      @snippet acsch.txt acsch


  **/

#include <boost/simd/function/scalar/acsch.hpp>
#include <boost/simd/function/simd/acsch.hpp>

#endif
