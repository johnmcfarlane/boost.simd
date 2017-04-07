//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ARG_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ARG_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-arg arg (function object)

    This function object calculates the phase angle (in radians) of the complex number z

    @headerref{<boost/simd/type/complex/function/arg.hpp>}

    @par Description

    @code
    IEEEValue arg(complex<IEEEValue> const& z);
    @endcode


    @par Notes

      - If no errors occur, returns the phase angle of z in the interval \f$]-\pi, \pi]\f$.

      - limit cases are properly handled using the pedantic_ decorator

      - The computation use @ref atan2, the pedantic version uses @ref  atan2 with pedantic_ decorator

    @see ( %real ) [arg](@ref  real-arg)

    @par Example:

       @snippet c_arg.cpp arg

    @par Possible output:

       @snippet c_arg.txt arg

  **/
} } }

#endif

#include <boost/simd/function/arg.hpp>
#include <boost/simd/type/complex/function/impl/arg.hpp>

#endif
