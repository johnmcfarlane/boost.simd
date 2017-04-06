//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_IEEE_HPP_INCLUDED
#define BOOST_SIMD_IEEE_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-ieee Ieee functions

   These functions provide scalar and SIMD algorithms for inspecting, generating or
   decomposing IEEE 754 floating point numbers.

   Operations such as exponent and mantissa
   extraction, floating point modulo, IEEE bit patterns manipulation and
   magnitude comparison are provided.

<center>
 |                                           |                                      |                                     |                                  |                                  |
 |:-----------------------------------------:|:------------------------------------:|:-----------------------------------:|:--------------------------------:|:--------------------------------:|
 |  [bitfloating](@ref real-bitfloating)     |  [bitinteger](@ref real-bitinteger)  |  [bitofsign](@ref real-bitofsign)   |  [copysign](@ref real-copysign)  |  [eps](@ref real-eps)            |
 |  [exponentbits](@ref real-exponentbits)   |  [exponent](@ref real-exponent)      |  [fpclassify](@ref real-fpclassify) |  [frac](@ref real-frac)          |  [frexp](@ref real-frexp)        |
 |  [ifrexp](@ref real-ifrexp)               |  [ilogb](@ref real-ilogb)            |  [ldexp](@ref real-ldexp)           |  [mantissa](@ref real-mantissa)  |  [maxmag](@ref real-maxmag)      |
 |  [maxnum](@ref real-maxnum)               |  [maxnummag](@ref real-maxnummag)    |  [minmag](@ref real-minmag)         |  [minnum](@ref real-minnum)      |  [minnummag](@ref real-minnummag)|
 |  [modf](@ref real-modf)                   |  [negate](@ref real-negate)          |  [negatenz](@ref real-negatenz)     |  [nextafter](@ref real-nextafter)|  [next](@ref real-next)          |
 |  [nextpow2](@ref real-nextpow2)           |  [predecessor](@ref real-predecessor)|  [prev](@ref real-prev)             |  [safe_max](@ref real-safe_max)  |  [safe_min](@ref real-safe_min)  |
 |  [saturate](@ref real-saturate)           |  [sign](@ref real-sign)              |  [signnz](@ref real-signnz)         |  [successor](@ref real-successor)|  [ulpdist](@ref real-ulpdist)    |
 |  [ulp](@ref real-ulp)                     |                                      |                                     |                                  |                                  |
</center>
  **/

} }

#include <boost/simd/function/bitfloating.hpp>
#include <boost/simd/function/bitinteger.hpp>
#include <boost/simd/function/bitofsign.hpp>
#include <boost/simd/function/copysign.hpp>
#include <boost/simd/function/eps.hpp>
#include <boost/simd/function/exponentbits.hpp>
#include <boost/simd/function/exponent.hpp>
#include <boost/simd/function/fpclassify.hpp>
#include <boost/simd/function/frac.hpp>
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/function/ifrexp.hpp>
#include <boost/simd/function/ilogb.hpp>
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/function/mantissa.hpp>
#include <boost/simd/function/maxmag.hpp>
#include <boost/simd/function/maxnum.hpp>
#include <boost/simd/function/maxnummag.hpp>
#include <boost/simd/function/minmag.hpp>
#include <boost/simd/function/minnum.hpp>
#include <boost/simd/function/minnummag.hpp>
#include <boost/simd/function/modf.hpp>
#include <boost/simd/function/negate.hpp>
#include <boost/simd/function/negatenz.hpp>
#include <boost/simd/function/nextafter.hpp>
#include <boost/simd/function/next.hpp>
#include <boost/simd/function/nextpow2.hpp>
#include <boost/simd/function/predecessor.hpp>
#include <boost/simd/function/prev.hpp>
#include <boost/simd/function/safe_max.hpp>
#include <boost/simd/function/safe_min.hpp>
#include <boost/simd/function/saturate.hpp>
#include <boost/simd/function/sbits.hpp>
#include <boost/simd/function/sign.hpp>
#include <boost/simd/function/signnz.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/simd/function/successor.hpp>
#include <boost/simd/function/ulpdist.hpp>
#include <boost/simd/function/ulp.hpp>

#endif
