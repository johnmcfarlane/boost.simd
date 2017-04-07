//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIGNNZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIGNNZ_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-signnz signnz (function object)

    This function object returns the sign of x. I.e. -1 or 1,
    depending on the fact  @c x is negative or positive.

    @headerref{<boost/simd/function/signnz.hpp>}

    @par Description

      @code
      Value signnz(Value const& x);
      @endcode

    @par Notes:

    - This function never returns @ref [Zero](@ref constant-Zero) (zero is considered positive for integers).

    - For floating point numbers the bit of sign is taken into account and so
    we always have `signnz(-z) == -signnz(z)` except is the entry is a NaN
    (in this later case the result is undefined).


    @see ( %real ) [Mzero](@ref constant-Mzero), [sign](@ref real-sign), [is_negative](@ref real-is_negative), [is_positive](@ref real-is_positive)

    @par Example:

      @snippet signnz.cpp signnz

    @par Possible output:

      @snippet signnz.txt signnz

  **/

#include <boost/simd/function/scalar/signnz.hpp>
#include <boost/simd/function/simd/signnz.hpp>

#endif
