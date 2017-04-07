//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FIRSTBITUNSET_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FIRSTBITUNSET_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-firstbitunset firstbitunset (function object)

    This function object returns the bit pattern in which the only bit set is
    the first bit unset (beginning with the least significant bit) in the parameter.

    @headerref{<boost/simd/function/firstbitunset.hpp>}

    @par Description

      @code
      as_integer_t<Value> firstbitunset(Value const& x);
      @endcode

    @see ( %real ) [ffs](@ref real-ffs), [firstbitset](@ref real-firstbitset)

    @par Example:

      @snippet firstbitunset.cpp firstbitunset

    @par Possible output:

      @snippet firstbitunset.txt firstbitunset

  **/

#include <boost/simd/function/scalar/firstbitunset.hpp>
#include <boost/simd/function/simd/firstbitunset.hpp>

#endif
