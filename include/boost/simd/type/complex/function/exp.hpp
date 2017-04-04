//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_EXP_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_EXP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

  /*!
    @ingroup group-complex
    @defgroup complex-exp exp (function object)
    This function object returns the complex exp argument: \f$e^{z}\f$

    @headerref{<boost/simd/type/complex/function/exp.hpp>}

    @par Description

    @code
    complex<IEEEValue> exp(complex<IEEEValue> const& z);
    @endcode


    @par Notes
      for z = x+iy

      - exp(conj(z)) == conj(exp(z))
      - If z is (\f$\pm\f$0,+0), the result is (1,+0)
      - If z is (x,\f$\infty\f$) (for any finite x), the result is (NaN,NaN)
      - If z is (x,NaN) (for any finite x), the result is (NaN,NaN)
      - If z is (\f$\infty\f$,+0), the result is (\f$\infty\f$, +0)
      - If z is (\f$-\infty\f$,y) (for any finite y), the result is (+0, \f$\pm0\f$0)
      - If z is (\f$\infty\f$, y) (for any finite nonzero y), the result is (\f$\infty e^{iy}\f$)
      - If z is (\f$-\infty\f$, +\f$\infty\f$), the result is (\f$\pm0\f$,\f$\pm0\f$) (signs are unspecified)
      - If z is (\f$\infty\f$,+\f$\infty\f$), the result is (\f$\pm\infty\f$,NaN) (the sign of the real part is unspecified)
      - If z is (\f$-\infty\f$,NaN), the result is (\f$\pm\f$0,\f$\pm0\f$) (signs are unspecified)
      - If z is (\f$\infty\f$,NaN), the result is (\f$\pm\infty\f$,NaN) (the sign of the real part is unspecified)
      - If z is (NaN,+0), the result is (NaN,+0)
      - If z is (NaN,y) (for any nonzero y), the result is (NaN,NaN)

    @see pow, log, log10


    @see ( %real ) exp

    @par Example:

       @snippet c_exp.cpp exp

    @par Possible output:

       @snippet c_exp.txt exp

  **/
  complex<IEEEValue> exp(complex<IEEEValue> const& z);
} }

#endif

#include <boost/simd/function/exp.hpp>
#include <boost/simd/type/complex/function/impl/exp.hpp>

#endif
