//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ALLBITS_ELSE_ZERO_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ALLBITS_ELSE_ZERO_HPP_INCLUDED

  /*!
    @ingroup group-boolean
    @defgroup real-if_allbits_else_zero if_allbits_else_zero (function object)

    This function object returns a mask of bits. All ones if the
    argument is non @ref [Zero](@ref constant-Zero) else all zeros.
    This is an alias of @ref [genmask](@ref real-genmask)

    @headerref{<boost/simd/function/if_allbits_else_zero.hpp>}

    @par Description

      @code

      @endcode

    @par Example:

      @snippet if_allbits_else_zero.cpp if_allbits_else_zero

    @par Possible output:

      @snippet if_allbits_else_zero.txt if_allbits_else_zero

  **/

#include <boost/simd/function/scalar/genmask.hpp>
#include <boost/simd/function/simd/if_allbits_else_zero.hpp>

#endif
