//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITINTEGER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITINTEGER_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-bitinteger bitinteger (function object)

    This function object transforms a floating point value
    in an integer with a preserving order formula.
    This function is the converse of @ref [bitfloating](@ref real-bitfloating).

    @headerref{<boost/simd/function/bitinteger.hpp>}

    @par Description

      @code
      as_integer_t<Value> bitinteger(Value const& x);
      @endcode

    @par Note:
    This function is related to the computation of
    floating successors or predecessors as the ordering of the integers obtained
    by @c bifloating is the same as the original order on the floating elements,
    an increment can be used to find the successor.

    @see ( %real ) [next](@ref real-next), [prev](@ref real-prev), [successor](@ref real-successor), [predecessor](@ref real-predecessor), [nextafter](@ref real-nextafter), [bitfloating](@ref real-bitfloating)

    @par Example:

      @snippet bitinteger.cpp bitinteger

    @par Possible output:

      @snippet bitinteger.txt bitinteger

  **/

#include <boost/simd/function/scalar/bitinteger.hpp>
#include <boost/simd/function/simd/bitinteger.hpp>

#endif
