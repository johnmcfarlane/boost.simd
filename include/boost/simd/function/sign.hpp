//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIGN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIGN_HPP_INCLUDED

  /*!
    @ingroup group-ieee
    @defgroup real-sign sign (function object)

    This function object returns the sign of @c x. i.e. -1, 0 or 1,
    depending on the fact  @c x is less than @ref [Zero](@ref constant-Zero), @ref [Zero](@ref constant-Zero) or
    greater than @ref [Zero](@ref constant-Zero).

    For floating,  the sign of @ref [Nan](@ref constant-Nan) is @ref [Nan](@ref constant-Nan),
    the sign of @ref [Mzero](@ref constant-Mzero) is also @ref [Zero](@ref constant-Zero).

    @headerref{<boost/simd/function/sign.hpp>}

    @par Description

      @code
      Value sign(Value const& x);
      @endcode

    @see ( %real ) [signnz](@ref real-signnz), [is_negative](@ref real-is_negative), [is_positive](@ref real-is_positive), [bitofsign](@ref real-bitofsign)

    @par Example:

      @snippet sign.cpp sign

    @par Possible output:

      @snippet sign.txt sign

  **/

#include <boost/simd/function/scalar/sign.hpp>
#include <boost/simd/function/simd/sign.hpp>

#endif
