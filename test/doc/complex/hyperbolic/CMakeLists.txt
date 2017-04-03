##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
   c_acosh.cpp
   c_asinh.cpp
   c_atanh.cpp
   c_cosh.cpp
   c_sinh.cpp
   c_tanh.cpp
   )

make_unit( "doc.complex.hyperbolic" ${SOURCES})
