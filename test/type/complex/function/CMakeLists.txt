##===================================================================================================
##                              Copyright 2017 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
      abs.cpp
      arg.cpp
      conj.cpp
      divides.cpp
      if_else.cpp
      is_equal.cpp
      is_eqz.cpp
      is_finite.cpp
      is_inf.cpp
      is_not_equal.cpp
      is_imag.cpp
      is_nan.cpp
      is_real.cpp
      minus.cpp
      mul_i.cpp
      multiplies.cpp
      plus.cpp
      sqr_abs.cpp
      sqrt.cpp
      unary_minus.cpp
      unary_plus.cpp
    )

make_unit( "type.complex.function" ${SOURCES})
make_coverage("type.complex.function" ${SOURCES})
