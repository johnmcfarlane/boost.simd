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
    @defgroup group-complex-abs Complex abs

    This function object returns the magnitude of the complex number z also
    named modulus or absolute value.

    `IEEEValue abs(complex<IEEEValue> const& z);`

    @par Header <boost/simd/type/complex/function/abs.hpp>

    @par Notes

     - limiting cases are properly handled using the pedantic_ decorator

     - The computation use @ref hypot, the pedantic version uses @ref hypot with pedantic_ decorator

    @par Example:

       @snippet c_abs.cpp abs

    @par Possible output:

       @snippet c_abs.txt abs

  **/
  IEEEValue abs(complex<IEEEValue> const& z);
} } }

#endif

#include <boost/simd/function/abs.hpp>
#include <boost/simd/type/complex/function/impl/abs.hpp>

#endif
