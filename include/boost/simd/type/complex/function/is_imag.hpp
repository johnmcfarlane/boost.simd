//==================================================================================================
/*!
  @file
  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCION_IS_IMAG_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCION_IS_IMAG_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-is_imag is_imag (object function)

    This function object returns True if and only if real part
    of the parameter is zero.

    @par Description

    @code
    as_logical<IEEEValue> is_imag(complex<IEEEValue> const& z);
    @endcode

    @par Header <boost/simd/type/complex/function/is_imag.hpp>

    @see (real) is_imag

    @par Example:

       @snippet c_is_imag.cpp is_imag

    @par Possible output:

       @snippet c_is_imag.txt is_imag

  **/
  as_logical<IEEEValue> boost::simd::is_imag(complex<IEEEValue);
} }
#endif

#include <boost/simd/function/is_imag.hpp>
#include <boost/simd/type/complex/function/impl/is_imag.hpp>

#endif
