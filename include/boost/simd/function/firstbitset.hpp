//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FIRSTBITSET_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FIRSTBITSET_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-firstbitset firstbitset (function object)

    This function object returns the bit pattern in which the only bit set is
    the first bit set (beginning with the least significant bit) in the parameter.

    @headerref{<boost/simd/function/firstbitset.hpp>}

    @par Description

      @code
      as_integer_t<Value> firstbitset(Value const& x);
      @endcode

    @see  ffs,  firstbitunset



    @par Example:

      @snippet firstbitset.cpp firstbitset

    @par Possible output:

      @snippet firstbitset.txt firstbitset

  **/

#include <boost/simd/function/scalar/firstbitset.hpp>
#include <boost/simd/function/simd/firstbitset.hpp>

#endif
