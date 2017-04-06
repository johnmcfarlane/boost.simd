//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_BITWISE_HPP_INCLUDED
#define BOOST_SIMD_BITWISE_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-bitwise Bitwise functions

      These functions provide scalar and SIMD algorithms for bit manipulations and bitwise
      operators. Bitwise operations are provided along more specific ones like bit-level rotations,
      bit set, get and toggling and mapping for compiler-specific first bit set or population count
      operations.

      All these functions can be included individually or all of them just by including <boost/simd/bitwise.hpp>

      Note that bitwise functions operators may accept floating types as arguments. The implied semantic
      is then that the operations are applied to the underlying bit patterns.

      - Bitwise operators

       <center>
         |                                       |                                            |                                            |                                            |                                          |
         |:-------------------------------------:|:------------------------------------------:|:------------------------------------------:|:------------------------------------------:|:----------------------------------------:|
         | [bitwise_and](@ref real-bitwise_and)  | [bitwise_andnot](@ref real-bitwise_andnot) |  [bitwise_cast](@ref real-bitwise_cast)    |  [bitwise_notand](@ref real-bitwise_notand)|  [bitwise_notor](@ref real-bitwise_notor)|
         | [bitwise_or](@ref real-bitwise_or)    | [bitwise_ornot](@ref real-bitwise_ornot)   |  [bitwise_select](@ref real-bitwise_select)|  [bitwise_xor](@ref real-bitwise_xor)      |  [complement](@ref real-complement)      |
       </center>


       Be aware that all binary bitwise functions return a result of the type of the first argument
       and that the second argument is only required to be of the same bit size as the first.
       This behaviour is intended to help bit masking in SIMD mode.

      - Bit manipulation, counts and locations

        <center>
         |                                       |                  |                 |                                |                           |                                      |
         |:-------------------------------------:|:----------------------------------:|:------------------------------:|:-------------------------:|:------------------------------------:|:------------------------------------------:|
         |  [bits](@ref real-bits)               |   [clz](@ref real-clz)             |  [ctz](@ref real-ctz)          | [ffs](@ref real-ffs)      | [firstbitset](@ref real-firstbitset) |   [firstbitunset](@ref real-firstbitunset) |
         |  [genmask](@ref real-genmask)         |   [genmaskc](@ref real-genmaskc)   |  [hi](@ref real-hi)            | [ilog2](@ref real-ilog2)  | [lo](@ref real-lo)                   |   [popcnt](@ref real-popcnt)               |
         |  [reversebits](@ref real-reversebits) |   [swapbytes](@ref real-swapbytes) |  [twopower](@ref real-twopower)|                           |                                      |                                            |
       </center>

      - Shifts and rotations

       <center>
         |                        |                                      |                                     |                            |                         |
         |:----------------------:|:------------------------------------:|:-----------------------------------:|:--------------------------:|:-----------------------:|
         | [rol](@ref real-rol)   |  [ror](@ref real-ror)                | [rrol](@ref real-rrol)              |  [rror](@ref real-rror)    |  [rshl](@ref real-rshl) |
         | [rshr](@ref real-rshr) |  [shift_left](@ref real-shift_left)  | [shift_right](@ref real-shift_right)|  [shl](@ref real-shl)      |  [shr](@ref real-shr)   |
       </center>

       shift_left and shift_right are logical shift, shl and shr arithmetic ones
       and rol and ror are rotations respectively to the left and to the right.
       For these functions negative or excessive values of the shift (greater
       or equal to the bit size of each shifted element) are errors.

       For the other ones negative values reverse the direction,  but excessive
       values are still erroneous.

  **/
} }

#include <boost/simd/function/bits.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_andnot.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/simd/function/bitwise_notand.hpp>
#include <boost/simd/function/bitwise_notor.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/bitwise_ornot.hpp>
#include <boost/simd/function/bitwise_select.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/clz.hpp>
#include <boost/simd/function/ctz.hpp>
#include <boost/simd/function/ffs.hpp>
#include <boost/simd/function/firstbitset.hpp>
#include <boost/simd/function/firstbitunset.hpp>
#include <boost/simd/function/genmaskc.hpp>
#include <boost/simd/function/genmask.hpp>
#include <boost/simd/function/hi.hpp>
#include <boost/simd/function/ilog2.hpp>
#include <boost/simd/function/lo.hpp>
#include <boost/simd/function/popcnt.hpp>
#include <boost/simd/function/reversebits.hpp>
#include <boost/simd/function/rol.hpp>
#include <boost/simd/function/ror.hpp>
#include <boost/simd/function/rrol.hpp>
#include <boost/simd/function/rror.hpp>
#include <boost/simd/function/rshl.hpp>
#include <boost/simd/function/rshr.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/simd/function/shl.hpp>
#include <boost/simd/function/shr.hpp>
#include <boost/simd/function/swapbytes.hpp>
#include <boost/simd/function/twopower.hpp>

#endif
