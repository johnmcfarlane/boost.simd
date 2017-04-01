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
    c_real.cpp
   )

make_unit( "doc.complex.arithmetic" ${SOURCES})
