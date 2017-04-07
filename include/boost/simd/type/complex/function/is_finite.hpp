//==================================================================================================
/*!
  @file
  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCION_IS_FINITE_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCION_IS_FINITE_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-is_finite is_finite (function object)

    This function object returns True if and only if real and imaginary part
    of the parameters are both finite.

    @headerref{<boost/simd/type/complex/function/is_finite.hpp>}

    @par Description

    @code
    as_logical<IEEEValue> is_finite(complex<IEEEValue> const& z);
    @endcode


    @see ( %real ) [is_finite](@ref  real-is_finite)

    @par Example:

       @snippet c_is_finite.cpp is_finite

    @par Possible output:

       @snippet c_is_finite.txt is_finite

  **/
  as_logical<IEEEValue> boost::simd::is_finite(complex<IEEEValue);
} }
#endif
#include <boost/simd/function/is_finite.hpp>
#include <boost/simd/type/complex/function/impl/is_finite.hpp>

#endif
