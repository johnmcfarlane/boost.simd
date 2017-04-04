//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_TANH_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_TANH_HPP_INCLUDED

  /*!
    @ingroup group-complex
    @defgroup complex-tanh tanh (object function)

    This function object computes complex hyperbolic tangent of a complex value z.

    @par Description

    @code
    IEEEValue tanh(complex<IEEEValue> const& z);
    @endcode

    @par Header <boost/simd/type/complex/function/tanh.hpp>

    @par Notes

     -  `tanh(conj(z))` is always equal to `conj(tanh(z))`

     -  `tanh(-z)` is always equal to `-tanh(z)`

        -  If z is (+0,+0), the result is (+0,+0)
        -  If z is (x,\f$\infty\f$) (for any finite non zero x), the result is (NaN,NaN)
        -  If z is (0,\f$\infty\f$) the result is (0,NaN)
        -  If z is (x, Nan) (for any finite non zero x), the result is (NaN,NaN)
        -  If z is (0, Nan) the result is (0,NaN)
        -  If z is (\f$\infty\f$,y) (for any finite positive y), the result is (1,+0)
        -  If z is (\f$\infty\f$,\f$\infty\f$), the result is (1,\f$\pm0\f$) (the sign of the imaginary part is unspecified)
        -  If z is (f$\infty\f$,NaN), the result is (1,\f$\pm0\f$) (the sign of the imaginary part is unspecified)
        -  If z is (NaN,+0), the result is (NaN,+0)
        -  If z is (NaN,y) (for any non-zero y), the result is (NaN,NaN)
        -  If z is (NaN,NaN), the result is (NaN,NaN)

     - Mathematical definition of hyperbolic tangent is  \f$ \frac{e^{-z}-e^{z}}{e^{-z}+e^{z}}\f$

    @see (real) tanh

    @par Example:

       @snippet c_tanh.cpp tanh

    @par Possible output:

       @snippet c_tanh.txt tanh

  **/
#include <boost/simd/function/tanh.hpp>
#include <boost/simd/type/complex/function/impl/tanh.hpp>

#endif
