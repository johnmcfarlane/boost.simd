//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_PREDICATES_HPP_INCLUDED
#define BOOST_SIMD_PREDICATES_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-predicates Predicates functions

      These functions provide scalar and SIMD algorithms for testing properties of values.
      Tests such as checks for validity, infinity, sign and others are provided. As for  [](@ref real-)
      group-boolean, these functions handle and return typed logical types.

    All these functions can be included individually or all of them just by including <boost/simd/predicates.hpp>

      - These predicates can be used through an operator
      <center>
        |  name                                            |  operator  |  name                                     |   operator  |
        |:------------------------------------------------:|:----------:|:-----------------------------------------:|:-----------:|
        |  [is_equal](@ref real-is_equal)                  | ==         |  [is_less_equal](@ref real-is_less_equal) |  <=         |
        |  [is_greater_equal](@ref real-is_greater_equal)  | >=         |  [is_less](@ref real-is_less)             |  <          |
        |  [is_greater](@ref real-is_greater)              | >          |  [is_not_equal](@ref real-is_not_equal)   |  !=         |
      </center>

         for floating entries negation as predicates as  is_not_greater(a, b) are not equivalent to
         !is_greater(a, b) due to possible  [](@ref real-)Nan values;

           @par Example:

              @snippet operators.cpp operators

           @par Possible output:

              @snippet operators.txt operators

      - The following ones have to be called directly.

        Many of these are restriction to special values of some of the preceding ones.
        Their use often provides speed gain in SIMD mode.

       <center>
        |                                              |                                                                        |                                                  |                                                         |
        |:--------------------------------------------:|:----------------------------------------------------------------------:|:------------------------------------------------:|:-------------------------------------------------------:|
        |  [is_denormal](@ref real-is_denormal)        |  [is_equal_with_equal_nans](@ref real-is_equal_with_equal_nans)        |  [is_eqz](@ref real-is_eqz)                      |  [is_even](@ref real-is_even)                           |
        |  [is_finite](@ref real-is_finite)            |  [is_flint](@ref real-is_flint)                                        |  [is_gez](@ref real-is_gez)                      |  [is_gtz](@ref real-is_gtz)                             |
        |  [is_imag](@ref real-is_imag)                |  [isincluded_c](@ref real-isincluded_c)                                |  [isincluded](@ref real-isincluded)              |  [is_inf](@ref real-is_inf)                             |
        |  [is_invalid](@ref real-is_invalid)          |  [is_lessgreater](@ref real-is_lessgreater)                            |  [is_lez](@ref real-is_lez)                      |  [is_ltz](@ref real-is_ltz)                             |
        |  [is_nan](@ref real-is_nan)                  |  [is_negative](@ref real-is_negative)                                  |  [is_nez](@ref real-is_nez)                      |  [is_ngez](@ref real-is_ngez)                           |
        |  [is_ngtz](@ref real-is_ngtz)                |  [is_nlez](@ref real-is_nlez)                                          |  [is_nltz](@ref real-is_nltz)                    |  [is_normal](@ref real-is_normal)                       |
        |  [is_not_denormal](@ref real-is_not_denormal)|  [is_not_equal_with_equal_nans](@ref real-is_not_equal_with_equal_nans)|  [is_not_greater](@ref real-is_not_greater)      |  [is_not_greater_equal](@ref real-is_not_greater_equal) |
        |  [is_not_imag](@ref real-is_not_imag)        |  [is_not_infinite](@ref real-is_not_infinite)                          |  [is_not_less_equal](@ref real-is_not_less_equal)|  [is_not_less](@ref real-is_not_less)                   |
        |  [is_not_nan](@ref real-is_not_nan)          |  [is_not_real](@ref real-is_not_real)                                  |  [is_odd](@ref real-is_odd)                      |  [is_ord](@ref real-is_ord)                             |
        |  [is_positive](@ref real-is_positive)        |  [is_real](@ref real-is_real)                                          |  [is_simd_logical](@ref real-is_simd_logical)    |  [is_unord](@ref real-is_unord)                         |
       </center>

         @par Example:

            @snippet predicates.cpp predicates

         @par Possible output:

            @snippet predicates.txt predicates
  **/

} }

#include <boost/simd/function/is_denormal.hpp>
#include <boost/simd/function/is_equal_with_equal_nans.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/is_even.hpp>
#include <boost/simd/function/is_finite.hpp>
#include <boost/simd/function/is_flint.hpp>
#include <boost/simd/function/is_gez.hpp>
#include <boost/simd/function/is_greater_equal.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/is_gtz.hpp>
#include <boost/simd/function/is_imag.hpp>
#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/function/is_invalid.hpp>
#include <boost/simd/function/is_less_equal.hpp>
#include <boost/simd/function/is_lessgreater.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/is_lez.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/is_nan.hpp>
#include <boost/simd/function/is_negative.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/is_ngez.hpp>
#include <boost/simd/function/is_ngtz.hpp>
#include <boost/simd/function/is_nlez.hpp>
#include <boost/simd/function/is_nltz.hpp>
#include <boost/simd/function/is_normal.hpp>
#include <boost/simd/function/is_not_denormal.hpp>
#include <boost/simd/function/is_not_equal_with_equal_nans.hpp>
#include <boost/simd/function/is_not_greater_equal.hpp>
#include <boost/simd/function/is_not_greater.hpp>
#include <boost/simd/function/is_not_imag.hpp>
#include <boost/simd/function/is_not_infinite.hpp>
#include <boost/simd/function/is_not_less_equal.hpp>
#include <boost/simd/function/is_not_less.hpp>
#include <boost/simd/function/is_not_nan.hpp>
#include <boost/simd/function/is_not_real.hpp>
#include <boost/simd/function/is_odd.hpp>
#include <boost/simd/function/is_ord.hpp>
#include <boost/simd/function/is_positive.hpp>
#include <boost/simd/function/is_real.hpp>
#include <boost/simd/function/is_unord.hpp>
#include <boost/simd/function/majority.hpp>

#endif

