//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_REDUCTION_HPP_INCLUDED
#define BOOST_SIMD_REDUCTION_HPP_INCLUDED

namespace boost {
namespace simd {
/*!
  @ingroup group-functions
  @defgroup group-reduction Reduction Functions

  These functions provide algorithms for in-register reduction and prefix-scan operations.

  They are usually only defined for **SIMD** types but may, in some
  cases such as  [sum](@ref real-sum) or   [prod](@ref real-prod), have a valid scalar semantic.

    <center>
|                                               |                                                     |                                           |                                                           |
|:---------------------------------------------:|:------------------------------------------------ --:|:-----------------------------------------:|:---------------------------------------------------------:|
|  [all](@ref real-all)                         |  [any](@ref real-any)                               |  [compare_equal](@ref real-compare_equal) |  [compare_greater_equal](@ref real-compare_greater_equal) |
|  [compare_greater](@ref real-compare_greater) |  [compare_less_equal](@ref real-compare_less_equal) |  [compare_less](@ref real-compare_less)   |  [compare_not_equal](@ref real-compare_not_equal)         |
|  [cummax](@ref real-cummax)                   |  [cummin](@ref real-cummin)                         |  [cumprod](@ref real-cumprod)             |  [cumsum](@ref real-cumsum)                               |
|  [dot](@ref real-dot)                         |  [hmsb](@ref real-hmsb)                             |  [isincluded](@ref real-isincluded)       |  [isincluded_c](@ref real-isincluded_c)                   |
|  [maximum](@ref real-maximum)                 |  [minimum](@ref real-minimum)                       |  [nbtrue](@ref real-nbtrue)               |  [none](@ref real-none)                                   |
|  [prod](@ref real-prod)                       |  [sum](@ref real-sum)                               |                                           |                                                           |
     </center>
**/
}
}

#include <boost/simd/function/all.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/compare_equal.hpp>
#include <boost/simd/function/compare_greater.hpp>
#include <boost/simd/function/compare_greater_equal.hpp>
#include <boost/simd/function/compare_less.hpp>
#include <boost/simd/function/compare_less_equal.hpp>
#include <boost/simd/function/compare_not_equal.hpp>
#include <boost/simd/function/cummax.hpp>
#include <boost/simd/function/cummin.hpp>
#include <boost/simd/function/cumprod.hpp>
#include <boost/simd/function/cumsum.hpp>
#include <boost/simd/function/dot.hpp>
#include <boost/simd/function/hmsb.hpp>
#include <boost/simd/function/isincluded.hpp>
#include <boost/simd/function/isincluded_c.hpp>
#include <boost/simd/function/maximum.hpp>
#include <boost/simd/function/minimum.hpp>
#include <boost/simd/function/nbtrue.hpp>
#include <boost/simd/function/none.hpp>
#include <boost/simd/function/prod.hpp>
#include <boost/simd/function/sum.hpp>

#endif
