//==================================================================================================
/*!
  @file
  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCION_IS_REAL_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCION_IS_REAL_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-is_real is_real (function object)

    This function object returns True if and only if imaginary part
    of the parameter is zero.

    @headerref{<boost/simd/type/complex/function/is_real.hpp>}

    @par Description

    @code
    as_logical<IEEEValue> is_real(complex<IEEEValue> const& z);
    @endcode


    @see ( %real ) [is_real](@ref  real-is_real)

    @par Example:

       @snippet c_is_real.cpp is_real

    @par Possible output:

       @snippet c_is_real.txt is_real

  **/
} }
#endif

#include <boost/simd/function/is_real.hpp>
#include <boost/simd/type/complex/function/impl/is_real.hpp>

#endif
