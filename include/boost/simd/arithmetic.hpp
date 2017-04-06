//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARITHMETIC_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-arithmetic Arithmetic functions

    These functions provide scalar and SIMD algorithms for classical arithmetic operators and
    functions of the C and C++ standard library. Other functions are also provided, in particular,
    provision for saturated operations through the use of a  [group](@ref real-group)-decorator.

    All these functions can be included individually or all of them just by including
    <boost/simd/arithmetic.hpp>

     - **Possibly saturated operations**

       The functors:
       <center>
         |                                       |                                     |                                 |                        |                           |
         |:-------------------------------------:|:-----------------------------------:|:-------------------------------:|:----------------------:|:-------------------------:|
         |  [abs](@ref real-abs)                 |  [dec](@ref real-dec)               |  [dist](@ref real-dist)         |  [inc](@ref real-inc)  |  [minus](@ref real-minus) |
         |  [multiplies](@ref real-multiplies)   |  [plus](@ref real-plus)             |  [oneminus](@ref real-oneminus) |  [sqr](@ref real-sqr)  |  [toint](@ref real-toint) |
         |  [unary_minus](@ref real-unary_minus) |  [unary_plus](@ref real-unary_plus) |  [touint](@ref real-touint)     |                        |                           |
       </center>

       can be decorated with `saturated_`. This decorator
       has no effect on floating calls,  but on integer calls replaces the operation by its
       saturated equivalent.

       Typically: overflows will be replaced by the  @ref Valmin/@ref Valmax proper value
       instead of providing undefined behaviour (for signed integral types) or wrapping
       modulo  @ref Valmax + 1 (for unsigned ones).

       Peculiarly saturated_( [abs](@ref real-abs)) and saturated_( [dist](@ref real-dist)) ensure that the result will
       never be stricly negative (which is for instance the case of `abs(Valmin<T>())` for
       @c T being any signed integral type).

        [toint](@ref real-toint) is a rather common operation as it converts floating number to signed integers
       of the same bit size, nevertheless it probably is its saturated version you have to use
       because it acts properly on large or not finite values, this is why an alias for
       `saturated_(toint)` is provided as  [ifix](@ref real-ifix).

       @par Example:

          @snippet saturated_abs.cpp saturated_abs

       @par Possible output:

          @snippet saturated_abs.txt saturated_abs_results

     - **Rounding operations**

        <center>
         |                                     |                                    |                             |                             |
         |:-----------------------------------:|:----------------------------------:|:---------------------------:|:---------------------------:|
         |  [ceil](@ref real-ceil)             |   [fix](@ref real-fix)             |  [floor](@ref real-floor)   |   [iceil](@ref real-iceil)  |
         |  [ifix](@ref real-ifix)             |   [ifloor](@ref real-ifloor)       |  [iround](@ref real-iround) |   [itrunc](@ref real-itrunc)|
         |  [inearbyint](@ref real-inearbyint) |   [nearbyint](@ref real-nearbyint) |  [round](@ref real-round)   |   [trunc](@ref real-trunc)  |
        </center>

          - The operations prefixed by 'i' return a value of the integral type iT
          associated to the entry type. (If T is the entry type iT is
          @c as_integer_t<T>)

          - The other ones return the same type as the entry.

        @par Example:

          @snippet roundings.cpp roundings

        @par Possible output:

          @snippet roundings.txt roundings_results

     - **Division operations**

         [divides](@ref real-divides) is the function associated to standard division. There is another one
        which provides more flexibility, namely rounded divisions.

        With two parameters  [div](@ref real-div) and  [divides](@ref real-divides) are equivalent, but  [div](@ref real-div) can admit
        a first option parameter that modifies its behaviour.

        <center>
         | option                             |          call           |      result similar to           |
         |------------------------------------|-------------------------|----------------------------------|
         |  [ceil](@ref real-ceil)            |   div(ceil, a, b)       |      T(ceil(fT(a)/fT(b)))        |
         |  [floor](@ref real-floor)          |   div(floor, a, b)      |      T(floor(fT(a)/fT(b)))       |
         |  [fix](@ref real-fix)              |   div(fix, a, b)        |      T(fix(fT(a)/fT(b)))         |
         |  [round](@ref real-round)          |   div(round, a, b)      |      T(round(fT(a)/fT(b)))       |
         |  [nearbyint](@ref real-nearbyint)  |   div(nearbyint, a, b)  |      T(nearbyint(fT(a)/fT(b)))   |
         |  [iceil](@ref real-iceil)          |   div(iceil, a, b)      |      iT(iceil(fT(a)/fT(b)))      |
         |  [ifloor](@ref real-ifloor)        |   div(ifloor, a, b)     |      iT(ifloor(fT(a)/fT(b)))     |
         |  [ifix](@ref real-ifix)            |   div(ifix, a, b)       |      iT(ifix(fT(a)/fT(b)))       |
         |  [iround](@ref real-iround)        |   div(iround, a, b)     |      iT(iround(fT(a)/fT(b)))     |
         |  [inearbyint](@ref real-inearbyint)|   div(inearbyint, a, b) |      iT(inearbyint(fT(a)/fT(b))) |
        </center>

           - The option parameter is described in the above table where a and b are of type T,
             fT is a supposed floating type associated to T (`as_floating_t<T>` if it
             exists) and iT is the integer type associated to T (`as_integer_t<T>`).
             (fT and iT are here only to support pseudo code description)

           @par Example:

              @snippet divisions.cpp divisions

           @par Possible output:

              @snippet divisions.txt divisions_results

     - **Remainder operations**

        [rem](@ref real-rem) is the remainder functor providing same kind of facilities as  [div](@ref real-div)

       With two parameters `rem(a, b)` is equivalent to   `rem(fix, a, b)`, but @c rem can admit
       a first optional parameter that modifies its behaviour and moreover can use the
       pedantic_ decorator to assure some limiting case values (see below).

       The option parameter can be chosen between  [ceil](@ref real-ceil),  [floor](@ref real-floor),
       [fix](@ref real-fix),  [round](@ref real-round),
       [nearbyint](@ref real-nearbyint) and if @c opt is the option, the call:

          @c rem(opt, a, b) is equivalent to  @c a-b*div(opt, a, b)

       For floating entries the underlisted corner cases are handled in the following way:
        - if  @c x is \f$\pm\infty\f$ ,  [](@ref real-)Nan is returned
        - if  @c x is \f$\pm0\f$ and  @c y is not  @c 0  @c x is returned if  @c pedantic_
          is used (else  @c 0: the sign bit is not preserved)
        - if  @c y is \f$\pm0\f$,  [](@ref real-)Nan is returned
        - if either argument is a nan,  a nan is returned

       @par Example:

          @snippet remainders.cpp remainders

       @par Possible output:

          @snippet remainders.txt remainders_results

     - **complex operations**

       Boost.SIMD  provides complex number operations. So
       the following functors can be used as being a restriction to real number of complex
       functions:

      <center>
        |                       |                         |                           |                        |                                |
        |:---------------------:|:-----------------------:|:-------------------------:|:----------------------:|:------------------------------:|
        |  [arg](@ref real-arg) |  [conj](@ref real-conj) |  [imag](@ref real-imag)   |  [real](@ref real-real)|  [sqr_abs](@ref real-sqr_abs)  |
      </center>

        For real entries  [conj](@ref real-conj) and real are identity, imag always 0,
         [sqr_abs](@ref real-sqr_abs) coincide with  [sqr](@ref real-sqr) and  [arg](@ref real-arg) results are always in the
        set \f$\{0, \pi,  Nan\}\f$

     - **Fused multiply-add operations**

      <center>
        |                      |                        |                               |                                  |
        |:--------------------:|:----------------------:|:-----------------------------:|:--------------------------------:|
        | [fma](@ref real-fma) | [fnma](@ref real-fnma) | [two_add](@ref real-two_add)  | [two_split](@ref real-two_split) |
        | [fms](@ref real-fms) | [fnms](@ref real-fnms) | [two_prod](@ref real-two_prod)|                                  |
      </center>

      These operations take three parmeters and compute some \f$\pm a * b \pm c \f$
      kind of expression, "n" standing for negate the result, "a" for add,
      "s" for substract and "m" for multiply.

      Correct fused multiply/add implies

      - only one rounding
      - no "intermediate" overflow

      The functions of this family provide this, BUT ONLY each time it is reasonable
      in terms of performance (mainly if the system has the hard
      wired capability).

      If you need "real" fused multiply-add capabilities in all circumstances in your own
      code you can use @c pedantic_(fma) (although it can be expansive) or
      @c std_(fma) (generally still more expansive) by using the decorators.

       [two_add](@ref real-two_add),  [two_prod](@ref real-two_prod) and  [two_split](@ref real-two_split) are used internally in @c pedantic_(fma)
      and can be useful in searching extra-accuracy in other circumstances as double-double
      computations.

      @c pedantic_(fma) is never used internally by Boost.SIMD

     - **Standard operations**

       The stdlibc++ provides them but only in scalar mode:

       <center>
         |                              |                           |                             |                            |
         |:----------------------------:|:-------------------------:|:---------------------------:|:--------------------------:|
         | [abs](@ref real-abs)         |  [ceil](@ref real-ceil)   |  [floor](@ref real-floor)   |  [fma](@ref real-fma)      |
         | [hypot](@ref real-hypot)     |  [max](@ref real-max)     |  [maxnum](@ref real-maxnum) |  [min](@ref real-min)      |
         | [minnum](@ref real-minnum)   |  [rem](@ref real-rem) (%) |  [remquo](@ref real-remquo) |  [round](@ref real-round)  |
         | [signbit](@ref real-signbit) |  [sqrt](@ref real-sqrt)   |                             |                            |
       </center>

       Boost.SIMD provides its own scalar and simd versions, but allows
       the use of the @c std_  [group](@ref real-group)-decorator to call the associated system
       library function if the user needs it.

     - **Other operations**

       <center>
         |                              |                                |                               |                              |                      |
         |:----------------------------:|:------------------------------:|:-----------------------------:|:----------------------------:|:--------------------:|
         | [average](@ref real-average) | [clamp](@ref real-clamp)       | [meanof](@ref real-meanof)    | [minmod](@ref real-minmod)   | [sqr](@ref real-sqr) |
         | [sqrt](@ref real-sqrt)       | [sqrt1pm1](@ref real-sqrt1pm1) | [tenpower](@ref real-tenpower) | [tofloat](@ref real-tofloat)|                      |
       </center>

        [clamp](@ref real-clamp) is also provided in stdlibc++ for scalar mode, but only since C++17.
       For now, in Boost.SIMD, the pedantic_  decorated version ensures standard
       conformity for a Nan first parameter.
  **/
} }

#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/arg.hpp>
#include <boost/simd/function/average.hpp>
#include <boost/simd/function/ceil.hpp>
#include <boost/simd/function/clamp.hpp>
#include <boost/simd/function/conj.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/dist.hpp>
#include <boost/simd/function/div.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/function/fix.hpp>
#include <boost/simd/function/floor.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/fms.hpp>
#include <boost/simd/function/fnma.hpp>
#include <boost/simd/function/fnms.hpp>
#include <boost/simd/function/hypot.hpp>
#include <boost/simd/function/iceil.hpp>
#include <boost/simd/function/ifix.hpp>
#include <boost/simd/function/ifloor.hpp>
#include <boost/simd/function/imag.hpp>
#include <boost/simd/function/inc.hpp>
#include <boost/simd/function/inearbyint.hpp>
#include <boost/simd/function/iround.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/function/meanof.hpp>
#include <boost/simd/function/min.hpp>
#include <boost/simd/function/minmod.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/oneminus.hpp>
#include <boost/simd/function/quadrant.hpp>
#include <boost/simd/function/real.hpp>
#include <boost/simd/function/rec.hpp>
#include <boost/simd/function/rem.hpp>
#include <boost/simd/function/remquo.hpp>
#include <boost/simd/function/nearbyint.hpp>
#include <boost/simd/function/round.hpp>
#include <boost/simd/function/rsqrt.hpp>
#include <boost/simd/function/signbit.hpp>
#include <boost/simd/function/sqr_abs.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/sqrt1pm1.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/function/tenpower.hpp>
#include <boost/simd/function/tofloat.hpp>
#include <boost/simd/function/toint.hpp>
#include <boost/simd/function/touint.hpp>
#include <boost/simd/function/trunc.hpp>
#include <boost/simd/function/two_add.hpp>
#include <boost/simd/function/two_prod.hpp>
#include <boost/simd/function/two_split.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/function/unary_plus.hpp>


#endif
