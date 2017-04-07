//==================================================================================================
/*!
  @file
  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCION_IS_NAN_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCION_IS_NAN_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-is_nan is_nan (function object)

    This function object returns True if and only if real or imaginary part
    of the parameters is a nan.

    @headerref{<boost/simd/type/complex/function/is_nan.hpp>}

    @par Description

    @code
    as_logical<IEEEValue> is_nan(complex<IEEEValue> const& z);
    @endcode


    @see ( %real ) [is_nan](@ref  real-is_nan)

    @par Example:

       @snippet c_is_nan.cpp is_nan

    @par Possible output:

       @snippet c_is_nan.txt is_nan

  **/
  as_logical<IEEEValue> boost::simd::is_nan(complex<IEEEValue);
} }
#endif
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/type/complex/function/impl/is_nan.hpp>

#endif
