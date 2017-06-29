##===================================================================================================
##                               Copyright 2017 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

set ( SOURCES
  iterator.arithmetic.cpp
  pointer.arithmetic.cpp
  pointer.logical.cpp
  mask.arithmetic.cpp
  mask.logical.cpp
  misaligned.arithmetic.cpp
#  misaligned.logical.cpp
)

make_unit( "function.scalar.aligned_load"   ${SOURCES})
make_coverage("function.scalar.aligned_load"  ${SOURCES})
