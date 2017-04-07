//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITWISE_NOT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITWISE_NOT_HPP_INCLUDED

  /*!
    @ingroup group-operator
    @defgroup real-bitwise_not bitwise_not (function object)

    This function object returns the return the bitwise bitwise_not of the entry
    Infix notation can be used with operator '~'
    This is a convenience alias of  [complement](@ref real-complement)

    @headerref{<boost/simd/function/bitwise_not.hpp>}

    @par Description

      @code
      Value bitwise_not(Value const& x);
      @endcode

    @par Example:

      @snippet bitwise_not.cpp bitwise_not

    @par Possible output:

      @snippet bitwise_not.txt bitwise_not

  **/

#include <boost/simd/function/scalar/complement.hpp>
#include <boost/simd/function/simd/bitwise_not.hpp>

#endif
