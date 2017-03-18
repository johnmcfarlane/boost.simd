## --------------------------------------------------------------------------------------
##                              Copyright 2017 - NumScale SAS
##
##                    Distributed under the Boost Software License Version 1.0
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## --------------------------------------------------------------------------------------

## benches for functor arg in simd complex mode.

set(SOURCES
    regular.double.m10_10.cpp
    regular.float.m10_10.cpp
)

make_bench("type.complex.simd.arg" ${SOURCES})

## --------------------------------------------------------------------------------------
