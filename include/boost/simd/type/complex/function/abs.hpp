//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ABS_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_ABS_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

namespace boost { namespace simd { namespace cmplx
{

  /*!
    @ingroup group-complex
    @defgroup complex-abs abs (function object)

    This function object returns the magnitude of the complex number z also
    named modulus or absolute value.

    @headerref{<boost/simd/type/complex/function/abs.hpp>}

    @par Description

        @code
        IEEEValue abs(complex<IEEEValue> const& z);
        @endcode


    @par Notes

     - limit cases are properly handled using the pedantic_ decorator

     - The computation use @ref hypot, the pedantic version uses @ref hypot with pedantic_ decorator


    @see ( %real ) abs, sqr_abs,  ( %complex ) [sqr_abs](@ref complex-sqr_abs)

    @par Example:

       @snippet c_abs.cpp abs

    @par Possible output:

       @snippet c_abs.txt abs

  **/
} } }

#endif

#include <boost/simd/function/abs.hpp>
#include <boost/simd/type/complex/function/impl/abs.hpp>

#endif
