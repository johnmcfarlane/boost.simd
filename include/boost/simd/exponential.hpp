//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_EXPONENTIAL_HPP_INCLUDED
#define BOOST_SIMD_EXPONENTIAL_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-exponential Exponential functions

    Those functions provide algorithms for computing exponentials
    and logarithms.

      <center>
        |                                         |                                   |                                     |                           |
        |:---------------------------------------:|:---------------------------------:|:-----------------------------------:|:-------------------------:|
        |  [cbrt](@ref real-cbrt)                 |  [exp10](@ref real-exp10)         |  [exp2](@ref real-exp2)             |  [exp](@ref real-exp)     |
        |  [expm1](@ref real-expm1)               |  [exprecneg](@ref real-exprecneg) |  [exprecnegc](@ref real-exprecnegc) |  [expx2](@ref real-expx2) |
        |  [log10](@ref real-log10)               |  [log2](@ref real-log2)           |  [log](@ref real-log)               |  [log1p](@ref real-log1p) |
        |  [nthroot](@ref real-nthroot)           |  [pow2](@ref real-pow2)           |  [pow_abs](@ref real-pow_abs)       |  [pow](@ref real-pow)     |
        |  [significants](@ref real-significants) |                                   |                                     |                           |
       </center>
  **/

} }

#include <boost/simd/function/cbrt.hpp>
#include <boost/simd/function/exp10.hpp>
#include <boost/simd/function/exp2.hpp>
#include <boost/simd/function/exp.hpp>
#include <boost/simd/function/expm1.hpp>
#include <boost/simd/function/exprecnegc.hpp>
#include <boost/simd/function/exprecneg.hpp>
#include <boost/simd/function/expx2.hpp>
#include <boost/simd/function/log10.hpp>
#include <boost/simd/function/log2.hpp>
#include <boost/simd/function/log.hpp>
#include <boost/simd/function/log1p.hpp>
#include <boost/simd/function/nthroot.hpp>
#include <boost/simd/function/pow2.hpp>
#include <boost/simd/function/pow_abs.hpp>
#include <boost/simd/function/pow.hpp>
#include <boost/simd/function/significants.hpp>

#endif
