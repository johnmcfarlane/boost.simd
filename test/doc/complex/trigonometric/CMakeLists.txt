##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
   c_acos.cpp
   c_asin.cpp
   c_cos.cpp
   c_sin.cpp
   )

make_unit( "doc.complex.trigonometric" ${SOURCES})
