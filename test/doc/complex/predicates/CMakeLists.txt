##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
   c_is_equal.cpp
   c_is_not_equal.cpp
   c_is_eqz.cpp
   c_is_finite.cpp
   c_is_imag.cpp
   c_is_invalid.cpp
   c_is_nan.cpp
   c_is_real.cpp
   )

make_unit( "doc.complex.predicates" ${SOURCES})
