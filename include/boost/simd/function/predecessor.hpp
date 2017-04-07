//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_PREDECESSOR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_PREDECESSOR_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-predecessor predecessor (function object)

    This function object returns the `n-`th greatest element strictly less than the parameter

    @headerref{<boost/simd/function/predecessor.hpp>}

    @par Description

      @code
      ///@{
      @endcode

    @par Note

     If @c n is null returns @c x else computes the `n`-th greatest representable value strictly less
     than @c x in its type.  @c n must be positive or null.

      - For integer types it saturates at @ref [Valmin](@ref constant-Valmin).

      - For floating point numbers, all @ref [Minf](@ref constant-Minf)  strict predecessors are @ref [Nan](@ref constant-Nan).

    @see ( %real ) [next](@ref real-next), [prev](@ref real-prev), [successor](@ref real-successor), [nextafter](@ref real-nextafter), [Minf](@ref constant-Minf), [Valmin](@ref constant-Valmin), [Nan](@ref constant-Nan)

    @par Example:

      @snippet predecessor.cpp predecessor

    @par Possible output:

      @snippet predecessor.txt predecessor

  **/

#include <boost/simd/function/scalar/predecessor.hpp>
#include <boost/simd/function/simd/predecessor.hpp>

#endif
