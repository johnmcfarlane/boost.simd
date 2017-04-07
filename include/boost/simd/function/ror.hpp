//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ROR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ROR_HPP_INCLUDED

  /*!
    @ingroup group-bitwise
    @defgroup real-ror ror (function object)

    This function object returns the first entry rotated right
    by the value of the second entry.

    @headerref{<boost/simd/function/ror.hpp>}

    @par Description

      @code
      Value ror(Value const& x, IntegerValue const& n);
      @endcode

    @par Note
    This function asserts if the integral parameter is out of range

    @see ( %real ) [rol](@ref real-rol), [rror](@ref real-rror), [rrol](@ref real-rrol)

    @par Example:

      @snippet ror.cpp ror

    @par Possible output:

      @snippet ror.txt ror

  **/

#include <boost/simd/function/scalar/ror.hpp>
#include <boost/simd/function/simd/ror.hpp>

#endif
