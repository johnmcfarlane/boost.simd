//==================================================================================================
/*!
  @file

  Convenience header for @projectname

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_HPP_INCLUDED
#define BOOST_SIMD_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/arch.hpp>
#include <boost/simd/as.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/detail/math.hpp>
#include <boost/simd/pack.hpp>

/// Main Boost namespace
namespace boost
{
  /// Main Boost.SIMD namespace
  namespace simd
  {
    /*!
      @defgroup group-api User's Manual

      The @projectname User's manual covers all the types, meta-functions, algorithms, functions
      and callable objects allowing the design and implementation of SIMD code.
    **/

    /*!
      @ingroup group-api
      @defgroup group-types Types and helpers

      @projectname provides a set of types to handle SIMD operations in a portable way.
      These types include:

      - boost::simd::pack which encapsulates SIMD registers
      - boost::simd::logical which encapsulates typed boolean values
    **/

    /*!
      @ingroup group-api
      @defgroup group-functions Functions and Constants

      @projectname functions and constants are designed to work seamlessly on both scalar
      and SIMD parameters. Their compile-time polymorphic behavior ensures that the best
      available implementation will be selected for any given combination of types, architecture
      and options (if any).

      While being documented as functions, most @projectname functions are actually Function Objects.
      This implementation allow @projectname to use its functions directly in standard algorithms
      and to support functions decorators to handle variations in functions' behavior.

      @projectname functions are accessible via the header files located in the
      @c boost/simd/function folder. E.g, boost::simd::abs requires the inclusion
      of boost/simd/function/abs.hpp.

      Similarly, @projectname constants are accessible via the header files located in the
      @c boost/simd/constant folder. E.g, boost::simd::True requires the inclusion
      of boost/simd/constant/true.hpp. All @projectname functions begin with a lower-case
      letter and all @projectname constants begin with an upper-case letter.

      Function semantics are usually similar to the pre-existing ones, if any, with the
      following caveats:

      - All functions are assumed to be @c noexcept.
      - Type mixing may be prohibited for fundamental types , i.e boost::simd::plus @c (char,char)
        is valid while boost::simd::plus @c (int,char) is not
      - Type promotion on result type may be disabled, i.e boost::simd::plus @c (char,char)
        returns @c char

      These limitations are due to the hardware implementation of these functions.
    **/
} }

#endif
