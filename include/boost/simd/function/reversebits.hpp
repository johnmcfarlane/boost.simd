//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REVERSEBITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REVERSEBITS_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-reversebits reversebits (function object)

    This function object returns the bits in reverse order for each scalar entry.

    @headerref{<boost/simd/function/reversebits.hpp>}

    @par Description

      @code
      IntegerValue reversebits(IntegerValue const& x);
      @endcode

    @see reverse,  swapbytes


    @par Example:

      @snippet reversebits.cpp reversebits

    @par Possible output:

      @snippet reversebits.txt reversebits

  **/

#include <boost/simd/function/scalar/reversebits.hpp>
#include <boost/simd/function/simd/reversebits.hpp>

#endif
