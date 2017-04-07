//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ASECH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ASECH_HPP_INCLUDED

  /*!
    @ingroup group-hyperbolic
    @defgroup real-asech asech (function object)

    This function returns the hyperbolic secant argument \f$\mathop{\textrm{acosh}}(1/x)\f$

    @headerref{<boost/simd/function/asech.hpp>}

    @par Description

      @code
      IEEEValue asech(IEEEValue const & x);
      @endcode

    @see ( %real ) [cosh](@ref real-cosh), [acosh](@ref real-acosh), [sinh](@ref real-sinh), [asinh](@ref real-asinh), [atanh](@ref real-atanh), [atanh](@ref real-atanh), [acoth](@ref real-acoth), [acsch](@ref real-acsch)

    @par Example:

      @snippet asech.cpp asech

    @par Possible output:

      @snippet asech.txt asech

  **/

#include <boost/simd/function/scalar/asech.hpp>
#include <boost/simd/function/simd/asech.hpp>

#endif
