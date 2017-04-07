//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_GENMASK_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GENMASK_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-genmask genmask (function object)

    This function object returns a mask of bits. This mask is full of ones if the
    input element is non @ref [Zero](@ref constant-Zero) else full of zeros.

    @headerref{<boost/simd/function/genmask.hpp>}

    @par Description

      @code

      @endcode

    @see ( %real ) [genmaskc](@ref real-genmaskc)

    @par Example:

      @snippet genmask.cpp genmask

    @par Possible output:

      @snippet genmask.txt genmask

    @par Alias:
    @c if_allbits_else_zero

    @see if_allbits_else

  **/

#include <boost/simd/function/scalar/genmask.hpp>
#include <boost/simd/function/simd/genmask.hpp>

#endif
