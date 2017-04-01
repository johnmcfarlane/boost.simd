//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IS_EQZ_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IS_EQZ_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup group-complex-is_eqz  Complex is_eqz

    This function object returns True if and only if real and imaginary part
    of the parameters are both zero.

    `as_logical<IEEEValue> is_eqz(complex<IEEEValue> const& z1,complex<IEEEValue> const& z2);`

    @par Header <boost/simd/type/complex/function/is_eqz.hpp>

    @par Example:

       @snippet c_is_eqz.cpp is_eqz

    @par Possible output:

       @snippet c_is_eqz.txt is_eqz

  **/
  as_logical<IEEEValue> boost::simd::is_eqz(complex<IEEEValue> const& z);
} }
#endif
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/type/complex/function/impl/is_eqz.hpp>

#endif
