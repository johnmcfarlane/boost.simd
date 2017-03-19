##===================================================================================================
##                              Copyright 2017 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
      abs.cpp
      acos.cpp
      acosh.cpp
      arg.cpp
      asin.cpp
      asinh.cpp
      atan.cpp
      atanh.cpp
      conj.cpp
      cos.cpp
      cosh.cpp
      divides.cpp
      exp.cpp
      exp_i.cpp
      exp_ipi.cpp
      if_else.cpp
      imag.cpp
      is_equal.cpp
      is_eqz.cpp
      is_finite.cpp
      is_inf.cpp
      is_not_equal.cpp
      is_imag.cpp
      is_invalid.cpp
      is_nan.cpp
      is_real.cpp
      ldexp.cpp
      log.cpp
      log10.cpp
      minus.cpp
      mul_i.cpp
      mul_mi.cpp
      multiplies.cpp
      plus.cpp
      polar.cpp
      pow.cpp
      proj.cpp
      real.cpp
      sin.cpp
      sinh.cpp
      sqr.cpp
      sqr_abs.cpp
      sqrt.cpp
      tan.cpp
      tanh.cpp
      unary_minus.cpp
      unary_plus.cpp
    )

make_unit( "type.complex.scalar.function" ${SOURCES})
make_coverage("type.complex.scalar.function" ${SOURCES})
