//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITFLOATING_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITFLOATING_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-bitfloating bitfloating (function object)

    This function object  transforms an integer value to a floating point one
    with a preserving order formula. This function is the converse of  [bitinteger](@ref real-bitinteger).

    @headerref{<boost/simd/function/bitfloating.hpp>}

    @par Description

      @code
      as_floating_t<Value> bitfloating(Value const& x);
      @endcode

    @par Note:
    This  function is  related to the computation of
    floating successors or predecessors as the ordering of the integers obtained
    by @c bifloating is the same as the original order on the floating elements,
    an increment can be used to find the successor.

    @see ( %real ) [next](@ref real-next), [prev](@ref real-prev), [successor](@ref real-successor), [predecessor](@ref real-predecessor), [nextafter](@ref real-nextafter), [bitinteger](@ref real-bitinteger)

    @par Example:

      @snippet bitfloating.cpp bitfloating

    @par Possible output:

      @snippet bitfloating.txt bitfloating

  **/

#include <boost/simd/function/scalar/bitfloating.hpp>
#include <boost/simd/function/simd/bitfloating.hpp>

#endif
