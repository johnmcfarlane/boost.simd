//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_SIN_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_SIN_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-sin sin (function object)
    This function object returns the complex sine of a complex value z.

    @headerref{<boost/simd/type/complex/function/sin.hpp>}

    @par Description

    @code
    complex<IEEEValue> sin(complex<IEEEValue> const& z);
    @endcode


    @par Notes

     - special cases are handled as if the operation is implemented by `-i*bs::sinh(i*z)`,
       where i is the imaginary unit.

    @see ( %real ) [sin](@ref  real-sin)

    @par Example:

       @snippet c_sin.cpp sin

    @par Possible output:

       @snippet c_sin.txt sin

  **/
  complex<IEEEValue> sin(complex<IEEEValue> const& z);
} }

#endif

#include <boost/simd/function/sin.hpp>
#include <boost/simd/type/complex/function/impl/sin.hpp>

#endif
