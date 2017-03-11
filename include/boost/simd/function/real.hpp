//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REAL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REAL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!

    @ingroup group-operator
    This function object returns the real part of the parameter.
    On real types it coincides with identity.

    @par Header <boost/simd/function/real.hpp>

    @see imag

    @par Example:

      @snippet real.cpp real

    @par Possible output:

      @snippet real.txt real

  **/
  Value real(Value const& x);
} }
#endif

#include <boost/simd/function/scalar/real.hpp>
#include <boost/simd/function/simd/real.hpp>

#endif
