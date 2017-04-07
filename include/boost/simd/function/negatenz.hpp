//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEGATENZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGATENZ_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-negatenz negatenz (function object)

    This function object returns @c x multiplied by the @ref signnz of @c y.
    The result is unspecified if @c y is @ref Nan

    @headerref{<boost/simd/function/negatenz.hpp>}

    @par Description

      @code
      Value negatenz(Value const& x, Value const& y);
      @endcode

    @par Note
    If @c x is  null the result is \f$\pm0\f$. Take care that @c negatenz distinguish
    between the signs of `T(0)` and `-T(0)` when `T` is a floating type.

    @see ( %real ) [negatenz](@ref real-negatenz), [Mzero](@ref constant-Mzero), [is_positive](@ref real-is_positive), [is_negative](@ref real-is_negative)

    @par Example:

      @snippet negatenz.cpp negatenz

    @par Possible output:

      @snippet negatenz.txt negatenz

  **/

#include <boost/simd/function/scalar/negatenz.hpp>
#include <boost/simd/function/simd/negatenz.hpp>

#endif
