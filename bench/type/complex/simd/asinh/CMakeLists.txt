## --------------------------------------------------------------------------------------
##                              Copyright 2017 - NumScale SAS
##
##                    Distributed under the Boost Software License Version 1.0
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
## --------------------------------------------------------------------------------------

## benches for functor asinh in simd complex mode.

set(SOURCES
    regular.double.m1_1.cpp
    regular.float.m1_1.cpp
)

make_bench("type.complex.simd.asinh" ${SOURCES})

## --------------------------------------------------------------------------------------
