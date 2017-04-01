##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
    c_exp.cpp
    c_exp_i.cpp
    c_exp_ipi.cpp
    c_log.cpp
    c_log10.cpp
    c_pow.cpp
   )

make_unit( "doc.complex.exponential" ${SOURCES})
