//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MANTISSA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MANTISSA_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-mantissa mantissa (function object)

    This function object returns the signed mantissa of the input argument.

    @headerref{<boost/simd/function/mantissa.hpp>}

    @par Description

      @code
      Value mantissa(Value const& x);
      @endcode

    @par Note
    The @ref exponent @c e and signed @ref mantissa @c m of a floating
    point entry @c x are related by
    \f$x = m\times 2^e\f$, with |m| \f$\in[1, 2[\f$. (Except for zero,
    for which \f$m = 0\f$).

    @see ( %real ) [frexp](@ref real-frexp), [pow](@ref real-pow), [exponent](@ref real-exponent)

    @par Example:

      @snippet mantissa.cpp mantissa

    @par Possible output:

      @snippet mantissa.txt mantissa

  **/

#include <boost/simd/function/scalar/mantissa.hpp>
#include <boost/simd/function/simd/mantissa.hpp>

#endif
