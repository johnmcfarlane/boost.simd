//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITS_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-bits bits (function object)

    This function object returns an unsigned integer value which has the same bits as the input

    @headerref{<boost/simd/function/bits.hpp>}

    @par Description

      @code
      as_integer_t<Value, unsigned> bits(Value const& x);
      @endcode

    @par Example:

      @snippet bits.cpp bits

    @par Possible output:

      @snippet bits.txt bits

  **/

#include <boost/simd/function/scalar/bits.hpp>
#include <boost/simd/function/simd/bits.hpp>

#endif
