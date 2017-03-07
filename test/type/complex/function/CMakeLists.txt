##===================================================================================================
##                              Copyright 2017 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
      abs.cpp
      is_equal.cpp
      is_not_equal.cpp
      plus.cpp
      sqrt.cpp
    )

make_unit( "type.complex.function" ${SOURCES})
make_coverage("type.complex.function" ${SOURCES})
