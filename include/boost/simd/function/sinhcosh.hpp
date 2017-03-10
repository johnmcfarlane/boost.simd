//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SINHCOSH_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SINHCOSH_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-hyperbolic

    This function object both computes the @c sinh and @c cosh of its argument using an algorithm
    faster than sequential calls to each function.

    The return type is implementation defined POD type that contains two members @c sinh and
    @c cosh that contains the results.

    @par Header <boost/simd/function/sinhcosh.hpp>

    @see  sinh, cosh

    @par Example:

      @snippet sinhcosh.cpp sinhcosh

    @par Possible output:

      @snippet sinhcosh.txt sinhcosh

  **/
  implementation-defined sinhcosh(IEEEValue const& x);
} }
#endif

#include <boost/simd/function/scalar/sinhcosh.hpp>
#include <boost/simd/function/simd/sinhcosh.hpp>

#endif
