//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_REAL_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_REAL_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-real real (object function)

    This function object computes the real part of the parameter.

    @par Description

    @code
    IEEEValue real(complex<IEEEValue> const& z);
    @endcode

    @par Header <boost/simd/type/complex/function/real.hpp>

    @see (real) real

    @par Example:

       @snippet c_real.cpp real

    @par Possible output:

       @snippet c_real.txt real

  **/
  IEEEValue boost::simd::real(complex<IEEEValue> const& z);
} }
#endif
#include <boost/simd/function/real.hpp>
#include <boost/simd/type/complex/function/impl/real.hpp>

#endif
