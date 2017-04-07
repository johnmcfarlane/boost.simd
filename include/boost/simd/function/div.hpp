//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIV_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIV_HPP_INCLUDED

  /*!
    @ingroup group-oerator
    @defgroup real-div div (function object)

    This function object computes the quotient of the two parameters of the
    same type with or without option.

    @headerref{<boost/simd/function/div.hpp>}

    @par Description

      @code

      @endcode

    @par Notes

    For any value @c x and @c y of same type `div({option, }x, y)`
    returns the quotient of @c x by @c y respecting to the option specified.

    With no option this function is equivalent to `divides(x, y)` (See @ref divides.)

    Options may be @ref ceil, @ref floor, @ref fix, @ref round, @ref nearbyint (in the
    namespace booost::simd) and provides the same result as if the function object whose
    option is the name was applied to the floating division of the parameters.

    @see ( %real ) [divides](@ref real-divides), [rec](@ref real-rec)

    @par Example:

      @snippet div.cpp div

    @par Possible output:

      @snippet div.txt div

  **/

#include <boost/simd/function/scalar/div.hpp>
#include <boost/simd/function/simd/div.hpp>


#endif
