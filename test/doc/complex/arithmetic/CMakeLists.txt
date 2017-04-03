##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
    c_abs.cpp
    c_arg.cpp
    c_conj.cpp
    c_imag.cpp
    c_ldexp.cpp
    c_mul_i.cpp
    c_mul_mi.cpp
    c_polar.cpp
    c_proj.cpp
    c_real.cpp
    c_sqr.cpp
    c_sqr_abs.cpp
   )

make_unit( "doc.complex.arithmetic" ${SOURCES})
